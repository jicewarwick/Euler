include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(53.combinatoricSelections main)

target_link_libraries(53.combinatoricSelections numberTheory)
