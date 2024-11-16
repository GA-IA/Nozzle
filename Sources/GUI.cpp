#include "GUI.h"
#include <iostream>

int GUI::Create() { return 0; }
void GUI::Clear() {}
void GUI::Present() {}
void GUI::Destroy() {}

ImGuiSystem::ImGuiSystem(){}

int ImGuiSystem::Create(SDL_Window* window, SDL_Renderer* renderer) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);
	return 0;
}

void ImGuiSystem::Clear(SDL_Event* sdlEvent) {
	ImGui_ImplSDL3_ProcessEvent(sdlEvent);
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
