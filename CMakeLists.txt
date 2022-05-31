cmake_minimum_required(VERSION 3.23)
project(VoronoiGen)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -std=c++17 -c -Wall -O3)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_library(voronoi_gen
        src/BeachLine.cpp
        src/Cell.cpp
        src/CircleEventQueue.cpp
        src/Diagram.cpp
        src/Edge.cpp
        src/Point2.cpp
        src/Vector2.cpp
        src/VoronoiGen.cpp
        )

add_executable(console_example examples/Console.cpp)
add_executable(opengl_example examples/OpenGL.cpp)

target_include_directories(voronoi_gen PUBLIC src/ src/MemoryPool)
target_include_directories(opengl_example PUBLIC lib/)
target_link_libraries(console_example  voronoi_gen )
target_link_libraries(opengl_example   voronoi_gen OpenGL::GL glfw )

