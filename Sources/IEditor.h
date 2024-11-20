#pragma once
#include <vector>

class EngineInsertor {	
protected:
	std::vector<Editor*> registered_class;
};

class IEditor : private EngineInsertor {
protected:
	void RegisterClass();
};

class Editor : protected IEditor {
protected:
	void OnEngineCreate();
	void OnRendererCreate();
	void OnGUICreate();

	void OnEngineLoop();
	void OnRendererLoop();
	void OnGUILoop();

	void OnGUIDestroy();
	void OnRendererDestroy();
	void OnEngineDestroy();
};