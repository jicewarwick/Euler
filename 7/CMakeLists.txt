include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(7.nthPrime main)

target_link_libraries(7.nthPrime numberTheory)
