cmake_minimum_required(VERSION 3.15)
project(mujoco_visualizer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(mujoco REQUIRED)
find_package(glfw3 REQUIRED)

add_subdirectory(l_callback)
add_subdirectory(l_control)
add_subdirectory(l_simulation)

add_executable(visualizer arm.cpp)

target_link_libraries(visualizer PRIVATE 
    l_simulation
    l_control
    l_callback
    mujoco::mujoco
    glfw
)
