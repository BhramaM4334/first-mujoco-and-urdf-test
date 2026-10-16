add_library(l_control  control.h control.cpp)
#since control needs callback, just link to callback

target_include_directories(l_control PUBLIC .)
target_link_libraries(l_control PUBLIC l_callback l_simulation mujoco::mujoco glfw)
