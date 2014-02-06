include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(2.sumbeforemillion main)

target_link_libraries(2.sumbeforemillion Fibonacci)
