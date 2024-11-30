cmake_minimum_required (VERSION 3.8)

add_library(ImGuiNode
"imgui_node_editor.cpp"
"imgui_node_editor_api.cpp"
"imgui_canvas.cpp"
"crude_json.cpp"
)
target_include_directories(ImGuiNode PRIVATE "${PROJECT_SOURCE_DIR}/Dependencies/imgui")
target_link_libraries(ImGuiNode PRIVATE ImGui)
