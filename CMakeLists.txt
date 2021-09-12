cmake_minimum_required(VERSION 3.10)
project(DataStructuresCourse C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -Wall")

# ================================================== PATHS ================================================== #

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/archive)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE})

message("# ---------------- PATHS ---------------- #")
message("src:                   ${CMAKE_CURRENT_SOURCE_DIR}")
message("bin:                   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("shared lib dir:        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message("static lib dir:        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

# ================================================== RESOURCES ================================================== #


# ================================================== LIBRARIES ================================================== #

include_directories(include)

add_library(type src/type.c)
add_library(primitivetypes src/primitives/int.c)
target_link_libraries(primitivetypes type)

add_library(ll src/ll.c)
target_link_libraries(ll type)

add_library(stack src/stack.c)
target_link_libraries(stack ll)

add_library(queue src/queue.c)
target_link_libraries(queue ll)

add_library(bst src/bst.c)
add_library(heap src/heap.c)
add_library(map src/map.c)
add_library(graph src/graph.c)
target_link_libraries(graph map)

# ================================================== LIB TESTS ================================================== #

add_subdirectory(Tests)

# ================================================== LAB TASKS ================================================== #

add_subdirectory(Tasks)

add_executable(Main main.c)