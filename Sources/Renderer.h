#pragma once
#include <iostream>
#include <SDL3/SDL.h>

class Renderer {
public:
	virtual int Create(SDL_Window* window);
	virtual void Clear();
	virtual void Present();
	virtual void Destroy();
};

class SDLRenderer : public Renderer {
private:
	SDL_Renderer* renderer;
public:
	int Create(SDL_Window* window);
	void Clear();
	void Present();
	void Destroy();
};