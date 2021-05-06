cmake_minimum_required(VERSION 3.10)
project(DataStructuresCourse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== PATHS ================================================== #

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/build/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})
set(CMAKE_PROJECT_DATABASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources/database)

message("# ---------------- PATHS ---------------- #")
message("src:                   ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin:                   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("shared lib dir:        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("database dir  :        ${CMAKE_PROJECT_DATABASE_DIRECTORY}")

# ================================================== INCLUDES ================================================== #

# ---------------- Library Headers ---------------- #
include_directories(lib/include)

# ---------------- TASKS ---------------- #
add_executable(L1T1 Tasks/Lab1/Task1.c)
add_executable(L1T2 Tasks/Lab1/Task2.c)
add_executable(L1T3 Tasks/Lab1/Task3.c)
add_executable(L1T4 Tasks/Lab1/Task4.c)

add_executable(L2T1 Tasks/Lab2/Task1.c)

add_executable(LT1T1 Tasks/LabTest1/Task1.c)
add_executable(LT1T2 Tasks/LabTest1/Task2.c)

add_executable(Main main.c)