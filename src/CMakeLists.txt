#/**********************************************************\
#
# Auto-generated CMakeLists.txt for the fugaplug project
#
#\**********************************************************/

# Written to work with cmake 2.6
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

Project(${PLUGIN_NAME})

file (GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.h
    [^.]*.cmake
    )

include_directories(${PLUGIN_INCLUDE_DIRS})

# Generated files are stored in ${GENERATED} by the project configuration
SET_SOURCE_FILES_PROPERTIES(
    ${GENERATED}
    PROPERTIES
	GENERATED 1
    )

SOURCE_GROUP(Generated FILES
    ${GENERATED}
    )

SET( SOURCES
    ${GENERAL}
    ${GENERATED}
    )

# This will include Win/projectDef.cmake, X11/projectDef.cmake, Mac/projectDef
# depending on the platform
include_platform()

# add path where to look for cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ";${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

# include everything for gstreamer #######################################
find_package(LibXml2 REQUIRED)
find_package(GStreamer REQUIRED)
#FIND_PACKAGE(libgstinterfaces-0.10.so)

link_directories(
    ${GSTREAMER_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIRS}
)
include_directories(
    ${GSTREAMER_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIRS}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${GSTREAMER_LIBRARIES}
    ${LIBXML2_LIBRARIES}
    /usr/lib/i386-linux-gnu/libgstinterfaces-0.10.so
)
