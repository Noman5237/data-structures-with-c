cmake_minimum_required(VERSION 3.10)
project(DataStructuresCourse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== LIB TESTS ================================================== #
include_directories(criterion/include)
find_library(CRITERION criterion criterion/lib)

add_executable(Test_Type type.c)
target_link_libraries(Test_Type type ${CRITERION})

add_executable(Test_Type_Int types/int.c)
target_link_libraries(Test_Type_Int primitivetypes ${CRITERION})
