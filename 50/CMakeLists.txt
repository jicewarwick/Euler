
include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(50.sumOfPrime main) 
add_executable(50.largestsum similar) 

target_link_libraries(50.sumOfPrime numberTheory)
target_link_libraries(50.largestsum numberTheory)
