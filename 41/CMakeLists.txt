include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(41.pandigitalPrime main)

target_link_libraries(41.pandigitalPrime numberTheory)
