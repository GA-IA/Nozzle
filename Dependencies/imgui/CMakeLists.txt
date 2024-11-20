cmake_minimum_required (VERSION 3.8)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

add_library(ImGui
"imgui.cpp" 
"imgui_demo.cpp" 
"imgui_draw.cpp" 
"imgui_impl_sdlrenderer3.cpp" 
"imgui_impl_sdl3.cpp" 
"imgui_stdlib.cpp" 
"imgui_tables.cpp" 
"imgui_widgets.cpp"
)
target_link_libraries(ImGui PRIVATE SDL3::SDL3)