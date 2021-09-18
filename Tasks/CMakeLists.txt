
cmake_minimum_required(VERSION 3.10)
project(DataStructuresCourse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== TASKS ================================================== #
add_executable(L1T1 Lab1/Task1.c)
add_executable(L1T2 Lab1/Task2.c)
add_executable(L1T3 Lab1/Task3.c)
add_executable(L1T4 Lab1/Task4.c)

add_executable(L2T1 Lab2/Task1.c)

add_executable(LT1T1 LabTest1/Task1.c)
add_executable(LT1T2 LabTest1/Task2.c)

add_executable(L4T1 Lab4/Task1.c)

add_executable(L5T1 Lab5/Task1.c)

add_executable(L6T1 Lab6/Task1.c)
target_link_libraries(L6T1 ll)
add_executable(L6T2 Lab6/Task2.c)
target_link_libraries(L6T2 stack)
add_executable(L6T3 Lab6/Task3.c)
target_link_libraries(L6T3 queue)

add_executable(L8T1 Lab8/Task1.c)
target_link_libraries(L8T1 bst)

add_executable(L10T1 Lab10/Task1.c)
target_link_libraries(L10T1 heap)

add_executable(L12T1 Lab12/Task1.c)
target_link_libraries(L12T1 bst)

add_executable(L12T2 Lab12/Task2.c)
target_link_libraries(L12T2 bst)

add_executable(L13T1 Lab13/Task1.c)
target_link_libraries(L13T1 map ll stack queue ilistbst primitivetypes)

add_executable(L13T2 Lab13/Task2.c)
target_link_libraries(L13T2 map ll stack queue ilistbst primitivetypes)

add_executable(L13T3 Lab13/Task3.c)
target_link_libraries(L13T3 map ll stack queue ilistbst primitivetypes)

add_executable(L14T1 Lab14/Task1.c)

# ================================================== LAB TESTS ================================================== #

add_library(lab2dll LabTest2/doubleLinkedList.c)

add_executable(LT2T1_1 LabTest2/Task1_1.c)
target_link_libraries(LT2T1_1 lab2dll)

add_executable(LT2T1_2 LabTest2/Task1_2.c)
target_link_libraries(LT2T1_2 lab2dll)

add_executable(LT2TC_2 LabTest2/TaskC_1.c LabTest2/TaskC_2.c)

add_executable(LT3T1 LabTest3/Task1.c LabTest3/BinarySearchTree.c)
add_executable(LT3T2 LabTest3/Task2.c LabTest3/BinarySearchTree.c)

add_executable(Quiz1 Quiz/Quiz1.c)