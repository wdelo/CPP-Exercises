#pragma once

template<class T>
class ObjectFactory
{
public:
	ObjectFactory();
	ObjectFactory(const char* _name);
	~ObjectFactory();
private:
	const char* m_pFactoryName;
};