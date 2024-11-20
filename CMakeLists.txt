# CMakeList.txt : CMake project for Nozzle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add dependencies directory
set(SDL3_DIR "${CMAKE_SOURCE_DIR}/Dependencies/SDL3-3.1.6/cmake")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/Dependencies/imgui")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Nozzle")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

# Add source to this project's executable.
add_executable (Nozzle 
"Sources/main.cpp" 
"Sources/Engine.cpp" 
"Sources/Renderer.cpp" 
"Sources/GUI.cpp" 
"Sources/IEditor.cpp" 
"Sources/IEditor.h" 
"Sources/GUI/MainMenu.cpp")

add_subdirectory(${IMGUI_DIR})

target_link_libraries(Nozzle PUBLIC SDL3::SDL3)
target_link_libraries(Nozzle PUBLIC ImGui)
target_include_directories(Nozzle PUBLIC "${CMAKE_CURRENT_BINARY_DIR}" "${IMGUI_DIR}")  

add_custom_command(TARGET Nozzle POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:Nozzle> $<TARGET_RUNTIME_DLLS:Nozzle>
  COMMAND_EXPAND_LISTS
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Nozzle PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
