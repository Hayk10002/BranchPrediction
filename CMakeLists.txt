cmake_minimum_required(VERSION 3.10)

project(CacheAwareMergeSort)

set(CMAKE_CXX_STANDARD 23)
add_executable(main main.cpp)

# Add the main executable as a test
enable_testing()

add_test(NAME MainTest1 COMMAND main 1000000  100)
add_test(NAME MainTest2 COMMAND main 3000000  33)
add_test(NAME MainTest3 COMMAND main 5000000  20)
add_test(NAME MainTest4 COMMAND main 8000000  13)
add_test(NAME MainTest5 COMMAND main 10000000 10)