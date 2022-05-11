cmake_minimum_required(VERSION 3.14)
project(stereo_util_proj)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
set(OPENCV_DIR /usr/local/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
get_filename_component(STEREO_UTIL_DIR ../stereo_util ABSOLUTE)
message(STATUS "========================")
message(STATUS "${STEREO_UTIL_DIR}")
message(STATUS "========================")
include_directories(${STEREO_UTIL_DIR})
find_library(STEREO_UTIL_LIB stereo_util HINTS ${STEREO_UTIL_DIR})
message(STATUS "========================")
message(STATUS "${STEREO_UTIL_LIB}")
message(STATUS "========================")
add_executable(stereo_util_test stereo_util_test.cpp)
target_link_libraries(stereo_util_test LINK_PUBLIC ${STEREO_UTIL_LIB} ${OpenCV_LIBS} gtest_main)

include(GoogleTest)
gtest_discover_tests(stereo_util_test)
