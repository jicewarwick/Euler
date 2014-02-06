include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(23.notsumofabundant main)

target_link_libraries(23.notsumofabundant numberTheory)
