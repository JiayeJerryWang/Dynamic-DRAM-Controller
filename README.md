
# Dynamic DRAM Controller in Heterogeneous Computing Systems

## Overview
This project involves the development of a **dynamic DRAM controller** designed for heterogeneous computing systems. Implemented in C++ using **Ramulator 2.0**, this controller leverages **reinforcement learning (RL)** techniques to optimize memory access scheduling dynamically. By utilizing **Q-learning** and memory state feature recognition, the controller can adapt to workload characteristics in real-time, improving overall system performance.

## Key Features:
- **Reinforcement Learning-based Scheduling**: Dynamically adapts to changing workload patterns using Q-learning.
- **Memory State Feature Recognition**: Allows the controller to make informed decisions based on current system conditions.
- **Real-Time Updates**: Continuous learning and updating of the scheduling model to maintain optimal performance.
- **Dynamic Scheduling**: Adapts memory access scheduling in response to the system’s workload characteristics.
- **14% CPI Improvement**: Achieved significant performance gains for both memory-intensive and compute-intensive workloads.
- **System-Wide Optimization**: Designed to improve the overall system throughput and memory utilization in heterogeneous environments.

## Performance
The dynamic DRAM controller has demonstrated significant performance improvements:
- **14% improvement in CPI**: Achieved average CPI reduction across a range of heterogeneous computing workloads.
- **Memory Utilization**: Improved overall memory utilization by dynamically adjusting memory access patterns based on real-time feedback.

## Future Improvements
- **Enhanced Learning Algorithms**: Experiment with other reinforcement learning algorithms (e.g., Deep Q-Learning) to further improve performance.
- **Workload-Specific Optimizations**: Customize memory scheduling for specific types of workloads to achieve even higher efficiency.
- **Benchmarking**: Extend the benchmarking framework to test across a broader set of heterogeneous systems.
