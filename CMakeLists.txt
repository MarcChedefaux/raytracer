cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 17)

project( raytracer )

find_package( OpenCV REQUIRED )

find_package(Threads REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS} ./submodules/)

add_executable( raytracer 
main.cpp
utils/color3.cpp
utils/vector3.cpp
utils/interval.cpp
scenes/camera.cpp 
scenes/scene.cpp 
material/lambertian.cpp
material/metal.cpp
material/dielectric.cpp
material/light.cpp
hitObject/hitObject.cpp
hitObject/sphere.cpp
hitObject/plane.cpp
hitObject/triangle.cpp
hitObject/mesh.cpp
raytracing_engine/ray.cpp
raytracing_engine/engine.cpp)

target_link_libraries( raytracer ${OpenCV_LIBS} Threads::Threads)
