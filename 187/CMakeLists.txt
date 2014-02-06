include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(187.semiPrime main)

target_link_libraries(187.semiPrime numberTheory)
