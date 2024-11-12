#include <iostream>
#include "Engine.h"

using namespace std;

Engine* Engine::engine{ nullptr };
mutex Engine::_mutex;

Engine* Engine::Instance() {
	lock_guard<mutex> lock(_mutex);
	if (engine == nullptr) {
		engine = new Engine();
	}
	return engine;
}

int Engine::Create(SDLWindowConfig config) {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		cerr << SDL_GetError() << "\n";
	}
	window = SDL_CreateWindow(config.title, config.width, config.height, config.flags);
	is_running = true;
	return 0;
}

void Engine::Loop() {
	SDL_Event sdlEvent;
	SDL_PollEvent(&sdlEvent);

	if (sdlEvent.type == SDL_EVENT_QUIT) {
		is_running = false;
	}
}

int Engine::Destroy() {
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}