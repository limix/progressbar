include_directories (${TEST_SOURCE_DIR}/lib)

add_executable(demo demo.c)
target_link_libraries(demo progressbar ${CURSES_LIBRARIES})
