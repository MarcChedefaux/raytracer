cmake_minimum_required(VERSION 2.8)

project( raytracer )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( raytracer main.cpp )

target_link_libraries( raytracer ${OpenCV_LIBS} )
