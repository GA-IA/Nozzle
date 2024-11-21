#pragma once
#include <vector>
#include <mutex>

class IEditor{
protected:
	virtual void OnEngineCreate();
	virtual void OnRendererCreate();
	virtual void OnGUICreate();

	virtual void OnEngineLoop();
	virtual void OnRendererLoop();
	virtual void OnGUILoop();

	virtual void OnGUIDestroy();
	virtual void OnRendererDestroy();
	virtual void OnEngineDestroy();
};

class Registrar {
private:
	//Singleton
	static Registrar* registrar;
	static std::mutex _mutex;
protected:
	//Singleton
	std::vector<IEditor*> registered_class;
	Registrar();
	~Registrar();
public:
	//Singleton
	Registrar(Registrar& other) = delete;
	void operator=(const Registrar&) = delete;
	static Registrar* Instance();
	//Registration
	void RegisterClass(IEditor* editor);
};