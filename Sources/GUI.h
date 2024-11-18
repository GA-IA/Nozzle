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