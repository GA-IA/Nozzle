// Nozzle.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <SDL3/SDL.h>

using namespace std;

int main()
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
		cerr << SDL_GetError() << "\n";
	}
	SDL_Window* window = SDL_CreateWindow("Nozzle", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (!window) {
		cerr << SDL_GetError() << "\n";
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer) {
		cerr << SDL_GetError() << "\n";
	}
	cout << "Hello Nozzle." << endl;
	bool isRunning = true;
	while (isRunning) {
		SDL_Event sdlEvent;
		SDL_PollEvent(&sdlEvent);

		if (sdlEvent.type == SDL_EVENT_QUIT) {
			isRunning = false;
		}
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
