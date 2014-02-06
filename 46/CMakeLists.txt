include_directories(${Euler_SOURCE_DIR}/libmath)

add_executable(46.Goldbach main) 

target_link_libraries(46.Goldbach numberTheory)
