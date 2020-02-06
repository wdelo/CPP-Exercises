#include "ObjectFactory.h"

#define LINK_CLASS_TO_NAME(c, s) { ObjectFactory<c> __factory##c = ObjectFactory<c>(s); }

template<class T>
ObjectFactory<T>::ObjectFactory() {}

template<class T>
ObjectFactory<T>::ObjectFactory(const char* _name) {
	m_pFactoryName = _name;
}

template<class T>
ObjectFactory<T>::~ObjectFactory() {}


Vehicle* createVehicleByName(const char* pszTypeName, const char* pszInstanceName) {
	Vehicle* pVehPtr = NULL;
	if (strcmp(pszTypeName, "car") == 0) {
		pVehPtr = new Car();
		pVehPtr->setName(pszInstanceName);

	}
	else if (strcmp(pszTypeName, "semi_truck") == 0) {
		pVehPtr = new SemiTruck();
		pVehPtr->setName(pszInstanceName);
	}
	else {
		printf("Error: no vehicle object type of that name found.\n");
		return NULL;
	}
	return pVehPtr;
}