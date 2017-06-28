include_directories (${TEST_SOURCE_DIR}/lib)

add_executable(demo demo.c)
if (CURSES_FOUND)
    target_link_libraries(demo progressbar ${CURSES_LIBRARIES})
endif()
