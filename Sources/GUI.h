#pragma once

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
class GUI {
public:
	virtual int Create();
	virtual void Clear();
	virtual void Present();
	virtual void Destroy();
};

class ImGuiSystem : public GUI {
public:
	ImGuiSystem();
	int Create(SDL_Window* window, SDL_Renderer* renderer);
	void Clear(SDL_Event* sdlEvent);
	void Present(SDL_Renderer* renderer);
	void Destroy();
};