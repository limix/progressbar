cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
include(cmake/limix.cmake)
limix_initialise()
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES C)
limix_config()

set(LIBS "")

find_package(Curses)
if (CURSES_FOUND)
  include_directories(${CURSES_INCLUDE_DIRS})
  add_definitions(-DCURSES_FOUND)
  list(APPEND LIBS ${CURSES_LIBRARIES})
endif()

limix_process_default_dirs()

limix_add_library(${PROJECT_NAME} ${PROJECT_VERSION}
  "${SOURCES}" "${HEADERS}" "${LIBS}")

add_subdirectory(test)