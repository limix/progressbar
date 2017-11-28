cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
file(STRINGS "VERSION" PROGRESSBAR_VERSION)
project(ProgressBar VERSION ${PROGRESSBAR_VERSION} LANGUAGES C)

include(GNUInstallDirs)

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

find_package(Curses)

if (CURSES_FOUND)
  include_directories(${CURSES_INCLUDE_DIRS})
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories(include)
include_directories(src)
add_subdirectory(src)

if (CURSES_FOUND)
  add_definitions(-DCURSES_FOUND)
endif()

add_library(progressbar SHARED src/progressbar.c)

add_library(progressbar_static STATIC src/progressbar.c)

set_target_properties(progressbar
  PROPERTIES
  VERSION ${PROGRESSBAR_VERSION}
  PUBLIC_HEADER include/progressbar/progressbar.h)

install(TARGETS progressbar
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION include/progressbar)
if (CURSES_FOUND)
  target_link_libraries(progressbar ${CURSES_LIBRARIES})
endif()

install(TARGETS progressbar_static
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION include/progressbar)
if (CURSES_FOUND)
  target_link_libraries(progressbar_static ${CURSES_LIBRARIES})
endif()

add_subdirectory(test)
enable_testing()
add_test(demo test/demo)
