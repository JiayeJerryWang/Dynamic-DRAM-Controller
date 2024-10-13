#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include <iostream>

#include "base/base.h"
#include "dram_controller/controller.h"
#include "dram_controller/scheduler.h"

namespace Ramulator {

struct State {
    std::vector<int> readRequests;
    std::vector<int> writeRequests;
    std::vector<int> readyRequests;
    std::vector<int> rowHitRequests;
};

class RLScheduler : public IScheduler, public Implementation {
  RAMULATOR_REGISTER_IMPLEMENTATION(IScheduler, RLScheduler, "RLScheduler", "RL-based DRAM Scheduler.")
  private:
    int numDevices = 1;
    int numFeatures = 4; 
    IDRAM* m_dram;
    std::map<int, std::vector<double>> parameters;
    double learningRate = 0.1;
    double discountFactor = 0.95;
    double epsilon = 0.1;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
    State currentState;

  
  public:
    void init() override {
        for (int deviceId = 0; deviceId < numDevices; deviceId++) {
            parameters[deviceId] = std::vector<double>(numDevices * numFeatures, 0.0);
        }
    };

    void setup(IFrontEnd* frontend, IMemorySystem* memory_system) override {
        m_dram = cast_parent<IDRAMController>()->m_dram;
    };

    ReqBuffer::iterator compare(ReqBuffer::iterator req1, ReqBuffer::iterator req2) override {
        bool ready1 = m_dram->check_ready(req1->command, req1->addr_vec);
        bool ready2 = m_dram->check_ready(req2->command, req2->addr_vec);
        bool rowHit1 = m_dram->check_rowbuffer_hit(req1->command, req1->addr_vec);
        bool rowHit2 = m_dram->check_rowbuffer_hit(req2->command, req2->addr_vec);

        // First, prioritize requests based on readiness
        if (ready1 && !ready2) {
            return req1;
        } else if (!ready1 && ready2) {
            return req2;
        }

        // If both are ready or both are not ready, check for row buffer hits
        if (rowHit1 && !rowHit2) {
            return req1;
        } else if (!rowHit1 && rowHit2) {
            return req2;
        }

        // If both or neither request results in a row buffer hit, fallback to FCFS
        if (req1->arrive <= req2->arrive) {
            return req1;
        } else {
            return req2;
        }
    }

   ReqBuffer::iterator get_best_request(ReqBuffer& buffer) override {
        if (buffer.size() == 0) {
            return buffer.end();
        }
        // currentState = observeState(buffer, numDevices);
        // int selectedDevice = selectDevice(currentState);
        // Select the best request based on the selected action
        for (auto& req : buffer) {
            req.command = m_dram->get_preq_command(req.final_command, req.addr_vec);
        }
        auto candidate = buffer.begin();
        for (auto next = std::next(buffer.begin()); next != buffer.end(); next++) {
            candidate = compare(candidate, next);
        }
        // std::cout << "Best request: " << candidate->type_id  << candidate->addr << std::endl;
        return candidate;
    }

    State observeState(ReqBuffer& buffer, int numDevices) {
        State state;
        state.readyRequests.resize(numDevices, 0);
        state.readRequests.resize(numDevices, 0);
        state.writeRequests.resize(numDevices, 0);
        state.rowHitRequests.resize(numDevices, 0);
        for (auto req = buffer.begin(); req != buffer.end(); req++) {
            if (m_dram->check_ready(req->command, req->addr_vec)) {
                state.readyRequests[req->source_id]++;
            }
            if (req->type_id == Request::Type::Read) {
                state.readRequests[req->source_id]++;
            } 
            if (req->type_id == Request::Type::Write) {
                state.writeRequests[req->source_id]++;
            }
            if (m_dram->check_rowbuffer_hit(req->command, req->addr_vec)) {
                state.rowHitRequests[req->source_id]++;
            }
        }
        return state;
    }

    double calculateQValue(int deviceId, const State& state) {
        double qValue = 0.0;
        for (size_t i = 0; i < state.readyRequests.size(); ++i) {
            qValue += parameters[deviceId][i] * state.readyRequests[i];
        }
        return qValue;
    }

    int selectDevice(const State& state) {
        if (dis(gen) < epsilon) {
            return static_cast<int>(dis(gen) * state.readyRequests.size());
        } else {
            int selectedDevice = 0;
            double maxQValue = calculateQValue(0, state);
            for (size_t i = 1; i < state.readyRequests.size(); ++i) {
                double qValue = calculateQValue(i, state);
                if (qValue > maxQValue) {
                    maxQValue = qValue;
                    selectedDevice = i;
                }
            }
            return selectedDevice;
        }
    }
};

}       // namespace Ramulator
