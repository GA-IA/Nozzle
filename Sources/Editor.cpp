#include "Editor.h"
#include <iostream>
#include "GUI.h"
using namespace std;

void Editor::Start() {
	
}
void Editor::Event() {
	
}
void Editor::Loop() {
	/*ImGui::SetWindowFontScale(2);
	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("Files")) {
		ImGui::MenuItem("New");
		ImGui::MenuItem("Open");
		if (ImGui::BeginMenu("Open recent")) {
			ImGui::MenuItem("main.cpp");
			ImGui::EndMenu();
		}
		ImGui::Separator();
		ImGui::MenuItem("Save");
		ImGui::MenuItem("Save as");
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Edit")) {
		ImGui::MenuItem("Undo");
		ImGui::MenuItem("Redo");
		ImGui::Separator();
		ImGui::MenuItem("Copy");
		ImGui::MenuItem("Paste");
		ImGui::Separator();
		ImGui::MenuItem("Preferences");
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Selection")) {
		ImGui::MenuItem("Select all");
		ImGui::MenuItem("Duplicate current line");
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Views")) {
		if (ImGui::BeginMenu("Zoom")) {
			ImGui::MenuItem("Zoom in");
			ImGui::MenuItem("Zoom out");
			ImGui::MenuItem("Restore zoom");
			ImGui::EndMenu();
		}
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();

	ImGui::DockSpaceOverViewport();*/
	
	node::Begin("My Editor", ImVec2(0.0, 0.0f));
	int uniqueId = 1;
	// Start drawing nodes.
	node::BeginNode(uniqueId++);
	ImGui::Text("Node A");
	node::BeginPin(uniqueId++, node::PinKind::Input);
	ImGui::Text("-> In");
	node::EndPin();
	ImGui::SameLine();
	node::BeginPin(uniqueId++, node::PinKind::Output);
	ImGui::Text("Out ->");
	node::EndPin();
	node::EndNode();
	node::End();
}
void Editor::Destroy() {
	
}