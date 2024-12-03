#include "GUI.h"
#include <iostream>

using namespace std;

int ImGuiSystem::Create(SDL_Window* window, SDL_Renderer* renderer) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO();
	io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	//io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io->BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
	io->BackendFlags |= ImGuiBackendFlags_RendererHasViewports;

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
}

void ImGuiSystem::Present(SDL_Renderer* renderer) {
	ImGui::Render();
	if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		// Update and Render additional Platform Windows
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();

		// TODO for OpenGL: restore current GL context.
	}
	ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
}

void ImGuiSystem::Destroy() {
	ImGui_ImplSDL3_Shutdown();
	ImGui_ImplSDLRenderer3_Shutdown();
	ImGui::DestroyContext();
}

int ImGuiNode::Create() {
	config.SettingsFile = "Simple.json";
	context = node::CreateEditor(&config);
	if (context == nullptr) {
		cerr << "Cannot Create Imgui Node" << "\n";
		return 1;
	}
	return 0;
}

void ImGuiNode::Clear() {
	node::SetCurrentEditor(context);
}

void ImGuiNode::Present() {
	node::SetCurrentEditor(nullptr);
}

void ImGuiNode::Destroy() {
	node::DestroyEditor(context);
}
