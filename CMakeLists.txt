cmake_minimum_required(VERSION 3.10)
project(DataStructuresCourse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== PATHS ================================================== #

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

message("# ---------------- PATHS ---------------- #")
message("src:                   ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin:                   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("shared lib dir:        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

# ================================================== INCLUDES ================================================== #

# ---------------- Library Headers ---------------- #
include_directories(lib/include)

# ================================================== RESOURCES ================================================== #
add_compile_definitions(RESOURCES_DIR=${})

# ---------------- TASKS ---------------- #
add_executable(L1T1 Tasks/Lab1/Task1.c)
add_executable(L1T2 Tasks/Lab1/Task2.c)
add_executable(L1T3 Tasks/Lab1/Task3.c)
add_executable(L1T4 Tasks/Lab1/Task4.c)

add_executable(L2T1 Tasks/Lab2/Task1.c)

add_executable(LT1T1 Tasks/LabTest1/Task1.c)
add_executable(LT1T2 Tasks/LabTest1/Task2.c)

add_executable(L4T1 Tasks/Lab4/Task1.c)

add_executable(L5T1 Tasks/Lab5/Task1.c)

# needs to be moved to lib

add_library(dll Tasks/Lab6/doubleLinkedList.c)

add_executable(L6T1 Tasks/Lab6/Task1.c)
target_link_libraries(L6T1 dll)

add_executable(L6T2 Tasks/Lab6/Task2.c)
target_link_libraries(L6T2 dll)

add_executable(L6T3 Tasks/Lab6/Task3.c)
target_link_libraries(L6T3 dll)

add_library(ltdll Tasks/LabTest2/doubleLinkedList.c)

add_executable(LT2T1_1 Tasks/LabTest2/Task1_1.c)
target_link_libraries(LT2T1_1 ltdll)

add_executable(LT2T1_2 Tasks/LabTest2/Task1_2.c)
target_link_libraries(LT2T1_2 ltdll)

add_executable(LT2TC_2 Tasks/LabTest2/TaskC_1.c Tasks/LabTest2/TaskC_2.c)

add_executable(Quiz1 Tasks/Quiz/Quiz1.c)

add_executable(Main main.c)