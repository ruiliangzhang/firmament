file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/sim)

set(SIM_DFS_SRC
  sim/dfs/google_block_distribution.cc
  sim/dfs/simulated_dfs.cc
  )

set(SIM_GOOGLE_TRACE_PROCESSOR_SRCS
  sim/google_trace_task_processor.cc
  )

set(SIM_SRC
  sim/event_manager.cc
  sim/google_trace_loader.cc
  sim/knowledge_base_simulator.cc
  sim/simulated_wall_time.cc
  sim/simulator_bridge.cc
  sim/simulator.cc
  sim/synthetic_trace_loader.cc
  sim/trace_utils.cc
  )

set(SIM_PROTOBUFS
  sim/event_desc.proto
  )

set(SIM_TESTS
  sim/simulator_bridge_test.cc
  sim/event_manager_test.cc
  )

###############################################################################
# Protocol buffers

PROTOBUF_LIST_COMPILE(SIM "${SIM_PROTOBUFS}")

###############################################################################
# Unit tests

foreach(T IN ITEMS ${SIM_TESTS})
  get_filename_component(TEST_NAME ${T} NAME_WE)
  add_executable(${TEST_NAME} ${T}
    $<TARGET_OBJECTS:base>
    $<TARGET_OBJECTS:engine>
    $<TARGET_OBJECTS:executors>
    $<TARGET_OBJECTS:messages>
    $<TARGET_OBJECTS:misc>
    $<TARGET_OBJECTS:misc_trace_generator>
    $<TARGET_OBJECTS:platforms_unix>
    $<TARGET_OBJECTS:scheduling>
    $<TARGET_OBJECTS:sim>
    $<TARGET_OBJECTS:storage>)
  target_link_libraries(${TEST_NAME}
    ${spooky-hash_BINARY} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY}
    ${Firmament_SHARED_LIBRARIES} ctemplate glog gflags hwloc protobuf)
  add_test(${TEST_NAME} ${TEST_NAME})
endforeach(T)