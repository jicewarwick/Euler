include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(25.Fibonacci main) 

target_link_libraries(25.Fibonacci Fibonacci)
