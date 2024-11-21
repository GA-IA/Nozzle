#include "IEditor.h"

using namespace std;

Registrar* Registrar::registrar{ nullptr };
mutex Registrar::_mutex;

Registrar::Registrar() {};
Registrar::~Registrar() {};

Registrar* Registrar::Instance() {
	lock_guard<mutex> lock(_mutex);
	if (registrar == nullptr) {
		registrar = new Registrar();
	}
	return registrar;
}
