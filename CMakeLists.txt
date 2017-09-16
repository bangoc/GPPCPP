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

set(DEPENDS dl png z pthread Xinerama Xfixes Xcursor Xft Xrender fontconfig jpeg)
set(PPP2code src/PPP2code/Graph.cpp
             src/PPP2code/GUI.cpp
             src/PPP2code/Simple_window.cpp
             src/PPP2code/Window.cpp)

add_executable(chapter12example1 src/chapter12_example1.cpp ${PPP2code})
target_link_libraries(chapter12example1 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter12example1 ${FLTK_LIBRARIES} ${DEPENDS})
endif()

add_executable(chapter12example2 src/chapter12_example2.cpp ${PPP2code})
target_link_libraries(chapter12example2 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter12example2 ${DEPENDS})
endif()

add_executable(chapter12example3 src/chapter12_example3.cpp ${PPP2code})
target_link_libraries(chapter12example3 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter12example3 ${DEPENDS})
endif()

add_executable(chapter13example1 src/chapter13_example1.cpp ${PPP2code})
target_link_libraries(chapter13example1 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter13example1 ${DEPENDS})
endif()

add_executable(chapter15example1 src/chapter15example1.cpp ${PPP2code})
target_link_libraries(chapter15example1 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter15example1 ${DEPENDS})
endif()

add_executable(chapter15example2 src/chapter15example2.cpp ${PPP2code})
target_link_libraries(chapter15example2 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter15example2 ${DEPENDS})
endif()

add_executable(chapter15example3 src/chapter15example3.cpp ${PPP2code})
target_link_libraries(chapter15example3 ${FLTK_LIBRARIES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(chapter15example3 ${DEPENDS})
endif()