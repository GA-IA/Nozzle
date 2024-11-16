// Nozzle.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Engine.h"

using namespace std;

int main(int argc, char* argv[])
{
	Engine* engine = Engine::Instance();
	SDLWindowConfig config = SDLWindowConfig(
		"Nozzle",
		1920,
		1080,
		SDL_WINDOW_RESIZABLE
	);
	engine->Create(config);
	while (engine->IsRunning()) {
		engine->Loop();
	}
	engine->Destroy();
	return 0;
}
