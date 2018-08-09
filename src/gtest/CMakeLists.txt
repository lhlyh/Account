cmake_minimum_required(VERSION 3.10)

include_directories(
    ${PROJECT_SOURCE_DIR}/gtest_lib/include
    ${PROJECT_SOURCE_DIR}/include
)

link_directories(
    ${PROJECT_SOURCE_DIR}/gtest_lib/lib
)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/core/ CORE_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/gtest/ GTEST_LIST)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(gtest_main ${GTEST_LIST} ${CORE_LIST})
target_link_libraries(gtest_main gtest)