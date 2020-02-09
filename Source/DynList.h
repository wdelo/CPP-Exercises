#pragma once

/** 
	This is a dynamic list template class with the ability to 
	push and pop elements both from the back and the front of
	the list. Users can add and remove elements at specified
	indices. 

	@author William Delo
	@version 8.2.2020
*/


template <class T>
class DynList {
public:
	DynList();
	~DynList();
	int length() const;									
	void pushBack(const T& _T);							
	void pushFront(const T& _T);						
	void popFront();
	void popBack();
	void add(const T& _T, const unsigned int index);
	void remove(const unsigned int index);
	void clear();
	void reserve(const unsigned int reservation);
	T& operator[](unsigned int index);

private:
	T* m_pArray;
	unsigned int m_iLength;
	unsigned int m_iReservedLength;
	unsigned int m_iStartIndex;

	void copyArray(T*& pCopyArray, unsigned int iStartIndex);
};