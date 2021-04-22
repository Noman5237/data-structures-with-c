cmake_minimum_required(VERSION 3.17)
project(DataStructuresCourse C)

set(CMAKE_C_STANDARD 99)

include_directories(lib/include)

# ---------------- TASKS ---------------- #
add_executable(L1T1 Tasks/Lab1/Task1.c)
add_executable(L1T2 Tasks/Lab1/Task2.c)
add_executable(L1T3 Tasks/Lab1/Task3.c)
add_executable(L1T4 Tasks/Lab1/Task4.c)

add_executable(Main main.c)