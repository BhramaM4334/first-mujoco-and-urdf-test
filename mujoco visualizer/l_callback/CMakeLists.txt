add_library(l_callback callback.cpp callback.h)
target_include_directories(l_callback PUBLIC .)

# l_callback needs to link to l_control because callback.cpp uses keyboardC, etc.
target_link_libraries(l_callback PUBLIC l_control mujoco::mujoco glfw)
