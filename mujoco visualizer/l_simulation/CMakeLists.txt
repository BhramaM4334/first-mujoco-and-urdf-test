add_library(l_simulation simulation.cpp simulation.h)

# EXPOSE the headers to the rest of the project
target_include_directories(l_simulation PUBLIC .)

target_link_libraries(l_simulation PUBLIC l_control l_callback mujoco::mujoco glfw)
