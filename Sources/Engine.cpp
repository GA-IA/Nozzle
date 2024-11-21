#include <iostream>
#include "Engine.h"

using namespace std;

Engine* Engine::engine{ nullptr };
mutex Engine::_mutex;

Engine::Engine() {};
Engine::~Engine() {};

Engine* Engine::Instance() {
	lock_guard<mutex> lock(_mutex);
	if (engine == nullptr) {
		engine = new Engine();
	}
	return engine;
}

int Engine::Create(SDLWindowConfig config) {
	//Subsystem
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		cerr << SDL_GetError() << "\n";
		return -1;
	}
	//Window
	window = SDL_CreateWindow(config.title, config.width, config.height, config.flags);
	//Renderer
	renderer = new SDLRenderer();
	renderer->Create(window);
	//GUI
	imgui = new ImGuiSystem();
	imgui->Create(window, renderer->Renderer());
	editor = new Editor();
	if (!editor) {
		cerr << "Cannot create Editor" << "\n";
	}
	is_running = true;
	editor->Start();
	return 0;
}

void Engine::Event() {
	SDL_Event sdlEvent;
	SDL_PollEvent(&sdlEvent);
	if (sdlEvent.type == SDL_EVENT_QUIT) {
		is_running = false;
	}
	imgui->Event(&sdlEvent);
	editor->Event();
}
void Engine::TopLoop() {
	imgui->Clear();
	renderer->Clear();
}
void Engine::BottomLoop() {
	imgui->Present(renderer->Renderer());
	renderer->Present();
}

void Engine::Loop() {
	Event();
	TopLoop();
	editor->Loop();
	BottomLoop();
}

void Engine::Destroy() {
	editor->Destroy();
	delete editor;
	imgui->Destroy();
	delete imgui;
	renderer->Destroy();
	delete renderer;
	SDL_DestroyWindow(window);
	SDL_Quit();
}