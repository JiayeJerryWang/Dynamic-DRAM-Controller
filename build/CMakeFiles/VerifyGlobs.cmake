# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# yaml-cpp-sources at ext/yaml-cpp/CMakeLists.txt:59 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/jerry/ECE511/ext/yaml-cpp/src/*.cpp")
set(OLD_GLOB
  "/home/jerry/ECE511/ext/yaml-cpp/src/binary.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/convert.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/depthguard.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/directives.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/emit.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/emitfromevents.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/emitter.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/emitterstate.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/emitterutils.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/exceptions.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/exp.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/memory.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/node.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/node_data.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/nodebuilder.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/nodeevents.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/null.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/ostream_wrapper.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/parse.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/parser.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/regex_yaml.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/scanner.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/scanscalar.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/scantag.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/scantoken.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/simplekey.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/singledocparser.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/stream.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/tag.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/jerry/ECE511/build/CMakeFiles/cmake.verify_globs")
endif()

# yaml-cpp-contrib-sources at ext/yaml-cpp/CMakeLists.txt:58 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/home/jerry/ECE511/ext/yaml-cpp/src/contrib/*.cpp")
set(OLD_GLOB
  "/home/jerry/ECE511/ext/yaml-cpp/src/contrib/graphbuilder.cpp"
  "/home/jerry/ECE511/ext/yaml-cpp/src/contrib/graphbuilderadapter.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/jerry/ECE511/build/CMakeFiles/cmake.verify_globs")
endif()
