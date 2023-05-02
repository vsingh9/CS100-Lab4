cmake_minimum_required(VERSION 3.2)
project(unit-test-exercise)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})

include_directories(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)

add_subdirectory(lib)
add_subdirectory(test)

ADD_EXECUTABLE(testAwardsCeremony
  test/awardTests.cpp
  lib/Awards.cpp
)

TARGET_LINK_LIBRARIES(testAwardsCeremony gtest)
TARGET_LINK_LIBRARIES(testAwardsCeremony gmock)
ADD_EXECUTABLE(testHailstone
  test/testHailstone.cpp
  lib/Hailstone.cpp
)

TARGET_LINK_LIBRARIES(testHailstone gtest)
add_executable(testTriangle
  test/testTri.cpp
  lib/Triangle.cpp
)

target_link_libraries(testTriangle gtest)
