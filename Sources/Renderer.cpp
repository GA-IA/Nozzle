#include "Renderer.h"

using namespace std;

int Renderer::Create(SDL_Window* window) { return 0; };
void Renderer::Clear() {};
void Renderer::Present() {};
void Renderer::Destroy() {};

int SDLRenderer::Create(SDL_Window* window) {
	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer) {
		cout << SDL_GetError() << "\n";
	}
	return 0;
}
void SDLRenderer::Clear() {
	SDL_SetRenderDrawColorFloat(renderer, 0.13, 0.10, 0.25, 1);
	SDL_RenderClear(renderer);
}

void SDLRenderer::Present() {
	SDL_RenderPresent(renderer);
}

void SDLRenderer::Destroy() {
	SDL_DestroyRenderer(renderer);
}
