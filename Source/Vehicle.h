#pragma once
#include "ObjectFactoryImp.h"
#include "stdio.h"
using namespace std;

class Vehicle
{
public:
	Vehicle() {}
	~Vehicle() {}
	virtual void printNameOfVehicle() {}
	virtual void printTypeOfVehicle() {}
	void setName(const char* _newName) { m_pVehicleName = _newName; }
	const char* getName() const { return m_pVehicleName; }
private:
	const char* m_pVehicleName;
};

class Car : public Vehicle
{
public:
	Car() {}
	~Car() {}
	void printTypeOfVehicle() { printf("Car\n"); }
	void printNameOfVehicle() { printf(getName()); }
};

class SemiTruck : public Vehicle
{
public:
	SemiTruck() {}
	~SemiTruck() {}
	void printTypeOfVehicle() { printf("Semi Truck\n"); }
	void printNameOfVehicle() { printf(getName()); }

};
