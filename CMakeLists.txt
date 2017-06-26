project(ProgressBar C)

cmake_minimum_required(VERSION 2.6.4)

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
  execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion
                  OUTPUT_VARIABLE GCC_VERSION)

  if (GCC_VERSION VERSION_GREATER 4.9)
    set (CMAKE_C_STANDARD 11)
  else ()
    set (CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")
  endif ()
else ()
  set (CMAKE_C_STANDARD 11)
endif ()

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)
include_directories(${CURSES_INCLUDE_DIRS})

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

file(STRINGS "VERSION" PROGRESSBAR_VERSION)

include_directories(include)
include_directories(lib)
add_subdirectory(lib)
add_subdirectory(test)

add_library(progressbar SHARED lib/progressbar.c lib/statusbar.c)
add_library(progressbar_static STATIC lib/progressbar.c lib/statusbar.c)

set_target_properties(progressbar
  PROPERTIES
  VERSION ${PROGRESSBAR_VERSION}
  PUBLIC_HEADER include/progressbar/progressbar.h)

install(TARGETS progressbar
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION lib
    PUBLIC_HEADER DESTINATION include/progressbar)
target_link_libraries(progressbar ${CURSES_LIBRARIES})

install(TARGETS progressbar_static
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/progressbar)
target_link_libraries(progressbar_static ${CURSES_LIBRARIES})

