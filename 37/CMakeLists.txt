include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(37.truncatablePrimes main)

target_link_libraries(37.truncatablePrimes numberTheory)
