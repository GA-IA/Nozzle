#pragma once

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

class ImGuiSystem{
private:
	ImGuiIO* io;
public:
	int Create(SDL_Window* window, SDL_Renderer* renderer);
	void Event(SDL_Event* sdlEvent);
	void Clear();
	void Present(SDL_Renderer* renderer);
	void Destroy();
};

#include "imgui_node_editor.h"

namespace node = ax::NodeEditor;
class ImGuiNode : public ImGuiSystem{
private:
	node::Config config;
	node::EditorContext* context = nullptr;
public:
	int Create();
	void Clear();
	void Present();
	void Destroy();
};