#pragma once
#include "DynList.h"

template<class T>
DynList<T>::DynList()
{
	m_iLength = 0;
	m_iReservedLength = 8;
	m_iStartIndex = 3;
	m_pArray = new T[m_iReservedLength];
}

template<class T>
DynList<T>::~DynList() 
{

	delete[] m_pArray;

}

// Returns the length of the list.
template<class T>
int DynList<T>::length() const
{

	return m_iLength;

}

/**
	Pushes an element to the front of the list.

	@param element The element that will be pushed 
	to the front the list.
*/
template<class T>
void DynList<T>::pushFront(const T& element)
{

	if (m_iStartIndex == 0) {
		reserve((m_iReservedLength * 4));	
	}

	m_pArray[--m_iStartIndex] = element;    
	m_iLength++;

}

/**
	Pushes an element to the back of the list.

	@param element The element that will be pushed
	to the back the list.
*/
template<class T>
void DynList<T>::pushBack(const T& element) 
{

	if (m_iLength + m_iStartIndex == m_iReservedLength) {
		reserve((m_iReservedLength * 4));
	}

	m_pArray[m_iStartIndex + m_iLength] = element;
	m_iLength++;

}

// Removes frontmost element by moving start index forward and decreasing length.
template<class T>
void DynList<T>::popFront() 
{

	m_iStartIndex++;
	m_iLength--;

}

// Removes backmost element by decreasing length.
template<class T>
void DynList<T>::popBack() 
{

	m_iLength--;

}

/**
	Adds an element to the list at a specified index.

	@param _T The element that will be added to the list.
	@param index The index where the element will be added
	@requires 0 <= index <= m_iLength
	@ensures The element _T will be added to the list 
*/
template<class T>
void DynList<T>::add(const T& _T, const unsigned int index)
{

	if (m_iLength + m_iStartIndex == m_iReservedLength) {
		reserve((m_iReservedLength * 4));
	}

	T* pCopyArray = new T[m_iReservedLength];
	copyArray(pCopyArray, m_iStartIndex);

	pCopyArray[index + m_iStartIndex] = _T;
	m_iLength++;

	for (unsigned int i = index; i < m_iLength; i++) {
		pCopyArray[i + m_iStartIndex + 1] = m_pArray[i + m_iStartIndex];
	}

	delete[] m_pArray;
	m_pArray = pCopyArray;

}

/**
	Removes an element from the list at a specified index.

	@param index The index of the element that will be removed. 
	@requires 0 <= index <= m_iLength
	@ensures The element will be removed from the list.
*/
template<class T>
void DynList<T>::remove(const unsigned int index) 
{

	T* pCopyArray = new T[m_iReservedLength];
	copyArray(pCopyArray, m_iStartIndex);

	for (unsigned int i = index; i < m_iLength - 1; i++) {
		pCopyArray[i + m_iStartIndex] = m_pArray[i + m_iStartIndex + 1];
	}

	delete[] m_pArray;
	m_pArray = pCopyArray;
	m_iLength--;

}

// Removes all elements from list by setting length to zero.
template<class T>
void DynList<T>::clear() 
{

	m_iLength = 0;

}

/**
	Reserves additional memory space in the array.

	@param reservation The additional space added to the array.
*/
template<class T>
void DynList<T>::reserve(const unsigned int reservation) 
{

	m_iReservedLength += reservation;
	unsigned int newStartIndex = (reservation / 2) - (m_iLength / 2);

	T* pCopyArray = new T[m_iReservedLength];
	copyArray(pCopyArray, newStartIndex);
	delete[] m_pArray;

	m_pArray = pCopyArray;
	m_iStartIndex = newStartIndex;

}

/**
	Returns the value of the element at the index of the list. Value can be changed.

	@requires 0 <= index <= m_iLength
*/
template<class T>
T& DynList<T>::operator[](unsigned int index) 
{

	return m_pArray[m_iStartIndex + index];

}

/**
	Copies the contents of the main member array into a passed by reference pointer. 

	@param pCopyArray The pointer to the copied elements of m_pArray. 
	@param iStartIndex The index where the elements will start to be copied.
*/
template<class T>
void DynList<T>::copyArray(T*& pCopyArray, unsigned int iStartIndex) 
{
	for (unsigned int i = 0; i < m_iLength; i++) {
		pCopyArray[i + iStartIndex] = m_pArray[i + m_iStartIndex];
	}
}