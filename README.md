# Ray Tracer Engine in C++ with OpenCV Image Saving

![raytraced_image](/results/scene6.png "Raytraced image")

## Overview
This project is a ray tracer engine implemented in C++ with a focus on realism and high-quality rendering. Ray tracing is a rendering technique that simulates the behavior of light rays as they interact with objects in a 3D scene. With the integration of OpenCV, we provide the capability to save the rendered images in various formats.

## Features

- Realistic Rendering: My ray tracer engine employs physically-based rendering techniques to create lifelike images with accurate lighting, shadows, and reflections.

- Multiple materials : Allow to create lights, mirrors, glasses, and others...

- Multiple objects : Allow to use Sphere, Plane, Triangles, and .obj meshes as on the image above.

- Customizable Scenes: Define your own 3D scenes, objects, and materials to create the visual environments you desire. Integrating json file to describe a scene.

- Multi-Threading: Utilize multi-threading to generate multiple images at the same time and then combining them to enhance results.


# Getting Started
To get started with this ray tracer engine, follow these steps:

1. Clone the repository to your local machine :
```bash
git clone https://github.com/MarcChedefaux/raytracer.git
```
2. Build the project using CMake :
```bash
mkdir build
cd build
cmake ..
make -j6 
```
3. Run the code :
```bash
./raytracer
```
4. Feel free to make changes to the scenes in the scene folder to see the different results !

## Contributing
Contributions to this project are welcome! Whether you'd like to add new features, fix bugs, or anything else, go as you want !

## Acknowledgments
First of all, thanks to Peter Shirley, Trevor David Black and Steve Hollaschfor for writing the book "RayTracing in One Weekend". This book gave me inspiration to create this code and little help at the beginning.
I would like to thank the open-source community for their valuable contributions and the creators of OpenCV for their powerful image processing library.

Happy ray tracing! 🌟