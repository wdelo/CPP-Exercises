#pragma once
#include "DynList.h"
#include <string>
#include "stdlib.h"

template<class T>
class Dictionary {
public:
	Dictionary();
	~Dictionary();

	class KeyValuePair {
	private:
		std::string string;
		T value;
	public:
		void setValue(T _value) { value = _value; }
		void setString(std::string _string) { string = _string; }
		T getValue() const { return value; }
		std::string getString() const { return string; }
	};

	void add(std::string _string, T _value);
	void remove(std::string _string);
	T lookup(std::string _string);
	bool contains(std::string _string);

private:
	DynList<KeyValuePair> hashTable[31];

	int hashASCII(std::string _string);
	void checkWord(std::string _string);

};
