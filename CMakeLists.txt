project(GPPCPP)
cmake_minimum_required(VERSION 2.6.3)

set(CMAKE_CXX_STANDARD 11)

set(FLTK_SKIP_OPENGL ON)

set(FLTK_SKIP_FLUID ON)

FIND_PACKAGE(FLTK REQUIRED)

MESSAGE(STATUS ${FLTK_FOUND})

MESSAGE(STATUS ${FLTK_INCLUDE_DIR})

MESSAGE(STATUS ${FLTK_LIBRARIES})

include_directories(${CMAKE_SOURCE_DIR}/src/PPP2code)

include_directories(${FLTK_INCLUDE_DIRS})

set(SOURCE_FILES src/chapter12_example1.cpp
                 src/PPP2code/Graph.cpp
                 src/PPP2code/GUI.cpp
                 src/PPP2code/Simple_window.cpp
                 src/PPP2code/Window.cpp)

add_executable(gppcpp ${SOURCE_FILES})

target_link_libraries(gppcpp ${FLTK_LIBRARIES})

target_link_libraries(gppcpp dl png z pthread Xinerama Xfixes Xcursor Xft Xrender fontconfig)