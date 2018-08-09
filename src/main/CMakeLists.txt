cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/main MAIN_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/core CORE_LIST)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(main ${MAIN_LIST} ${CORE_LIST})