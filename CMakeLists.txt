cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 17)

project( raytracer )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} ./submodules/tqdm-cpp/ ./submodules/json/single_include/)

add_executable( raytracer main.cpp )

target_link_libraries( raytracer ${OpenCV_LIBS} )
