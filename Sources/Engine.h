#pragma once
#include <mutex>
#include <SDL3/SDL.h>
#include "Renderer.h"
#include "GUI.h"

struct SDLWindowConfig {
	const char* title;
	int width;
	int height;
	SDL_WindowFlags flags;
};

class Engine {
private:
	//Singleton
	static Engine* engine;
	static std::mutex _mutex;

	//Engine
	bool is_running = false;
	SDL_Window* window;
	//Renderer
	SDLRenderer* renderer;
	//GUI
	ImGuiSystem* imgui;
protected:
	//Singleton
	Engine();
	~Engine();
public:
	//Singleton
	Engine(Engine& other) = delete;
	void operator=(const Engine&) = delete;
	static Engine* Instance();
	//Engine
	bool IsRunning() {
		if (is_running) {
			return true;
		}
		return false;
	}
	int Create(SDLWindowConfig config);
	void Loop();
	void Destroy();
};