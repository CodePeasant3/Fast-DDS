find_package(PythonInterp 3)

execute_process(COMMAND ${ACTUAL_TEST} ${ACTUAL_ARGS})

execute_process(COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../../tools/fastdds/fastdds.py shm clean)
