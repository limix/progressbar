include_directories (${TEST_SOURCE_DIR}/src)

add_executable(demo demo.c)
target_link_libraries(demo progressbar_static)
if (CURSES_FOUND)
    target_link_libraries(demo ${CURSES_LIBRARIES})
endif()
