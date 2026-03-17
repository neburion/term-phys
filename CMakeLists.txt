cmake_minimum_required(VERSION 3.20)
project(tphys)
# =================================================================================================
# Config
# =================================================================================================
set(CXX_STANDARD       20)
set(LIBS               ncurses)
set(GTEST_TAG          v1.15.2)
set(WARN_FLAGS         -Wall -Wextra -Wpedantic)
set(SANITIZE_FLAGS     -fsanitize=undefined,address,leak)
# =================================================================================================
# CMake Settings
# =================================================================================================
set(CMAKE_CXX_STANDARD          ${CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
# =================================================================================================
# Sources
# =================================================================================================
file(GLOB_RECURSE SRC        src/*.cpp)
file(GLOB_RECURSE TEST_FILES tests/*.cpp)
list(FILTER SRC EXCLUDE REGEX "src/main.cpp")
# =================================================================================================
# Main Binary
# =================================================================================================
add_executable(${PROJECT_NAME} src/main.cpp ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:${WARN_FLAGS} ${SANITIZE_FLAGS}>
)
target_link_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:${SANITIZE_FLAGS}>
)
# =================================================================================================
# GTest
# =================================================================================================
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        ${GTEST_TAG}
)
FetchContent_MakeAvailable(googletest)
# =================================================================================================
# Test Binary
# =================================================================================================
add_executable(${PROJECT_NAME}_tests ${TEST_FILES} ${SRC})
target_include_directories(${PROJECT_NAME}_tests PRIVATE include)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${LIBS} GTest::gtest_main)
target_compile_options(${PROJECT_NAME}_tests PRIVATE ${WARN_FLAGS})
target_link_options(${PROJECT_NAME}_tests PRIVATE "")
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests DISCOVERY_MODE PRE_TEST)
