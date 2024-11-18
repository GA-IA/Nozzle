#include "GUI.h"
#include <iostream>

int ImGuiSystem::Create(SDL_Window* window, SDL_Renderer* renderer) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO();
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
	return 0;
}

void ImGuiSystem::Event(SDL_Event* sdlEvent) {
	ImGui_ImplSDL3_ProcessEvent(sdlEvent);
}

void ImGuiSystem::Clear() {
	ImGui_ImplSDL3_NewFrame();
	ImGui_ImplSDLRenderer3_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
}

void ImGuiSystem::Present(SDL_Renderer* renderer) {
	ImGui::Render();
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
}

void ImGuiSystem::Destroy() {
	ImGui_ImplSDL3_Shutdown();
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui::DestroyContext();
}
