find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(Fibonacci SHARED Fibonacci)
add_library(pandigitalPrime SHARED pandigitalPrime)
add_library(numberTheory SHARED numberTheory)
add_library(Tree SHARED Tree)

add_executable(gtest_example numberTheory_gtest.cpp)
target_link_libraries(gtest_example numberTheory gtest)
