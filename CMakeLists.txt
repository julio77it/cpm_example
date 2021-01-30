cmake_minimum_required(VERSION 3.0.0)
project(cpm_example VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

#
# CPM features
#
set(CPM_DOWNLOAD_VERSION 0.27.2) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

#
# External dependecies
#
CPMAddPackage(
  NAME Catch2
  GITHUB_REPOSITORY catchorg/Catch2
  VERSION 2.13.4
)

CPMAddPackage(
  NAME spdlog
  GITHUB_REPOSITORY gabime/spdlog
  VERSION 1.8.2
)

CPMAddPackage(
  NAME benchmark
  GITHUB_REPOSITORY google/benchmark
  VERSION 1.5.2
  OPTIONS "BENCHMARK_ENABLE_TESTING Off"
)
#if(spdlog_ADDED)	 
#    add_library(spdlog INTERFACE)	 
#    target_include_directories(spdlog INTERFACE ${spdlog_SOURCE_DIR})	 
#endif()

#
# Project Configuration
#
set(WARNING_FLAGS "-fno-omit-frame-pointer -fconcepts -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2")

set(CMAKE_C_FLAGS_DEBUG "-g -fsanitize=address -fsanitize=leak ${WARNING_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE "-O4 ${WARNING_FLAGS}")

configure_file("${PROJECT_SOURCE_DIR}/include/version.h.in"
               "${PROJECT_BINARY_DIR}/include/version.h")

include_directories(${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_BINARY_DIR}/include)

#
# Binary
#
add_executable(binary
               src/main.cpp)

set_target_properties(binary PROPERTIES COMPILE_FLAGS "${WARNING_FLAGS}")

target_link_libraries(binary
                      PRIVATE asan
                      PRIVATE lsan
                      PRIVATE spdlog)

target_include_directories(binary
                           PRIVATE spdlog)

#
# unit test
#
add_executable(unit_test
	           test/unit.cpp)

set_target_properties(unit_test PROPERTIES COMPILE_FLAGS "${WARNING_FLAGS}")

target_link_libraries(unit_test
					  PRIVATE asan
					  PRIVATE lsan
					  PRIVATE spdlog
					  PRIVATE Catch2)

target_include_directories(unit_test
						   PRIVATE spdlog
               PRIVATE Catch2)

#
# benchmark test
#
add_executable(benchmark_test
	           test/benchmark.cpp)

set_target_properties(benchmark_test PROPERTIES COMPILE_FLAGS "${WARNING_FLAGS}")

target_link_libraries(benchmark_test
					  PRIVATE asan
					  PRIVATE lsan
					  PRIVATE spdlog
					  PRIVATE benchmark)

target_include_directories(benchmark_test
						   PRIVATE spdlog
						   PRIVATE benchmark)                     