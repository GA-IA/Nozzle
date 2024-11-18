#pragma once
#include <iostream>
#include <SDL3/SDL.h>

class SDLRenderer{
private:
	SDL_Renderer* renderer;
public:
	SDL_Renderer* Renderer() {
		return renderer;
	}
	int Create(SDL_Window* window);
	void Clear();
	void Present();
	void Destroy();
};