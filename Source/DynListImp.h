#include "DynList.h"
using namespace std;

template<class T>
DynList<T>::DynList()
{
	m_iLength = 0;
	m_iReservedLength = 8;
	m_iStartIndex = 3;
	m_pArray = new T[m_iReservedLength];
}

template<class T>
DynList<T>::~DynList() {
	delete[] m_pArray;
}

template<class T>
int DynList<T>::length() const {
	return m_iLength;
}

template<class T>
void DynList<T>::pushFront(const T& element) {
	if (m_iStartIndex == 0) {
		reserve((m_iReservedLength * 4));
	}
	m_pArray[--m_iStartIndex] = element;
	m_iLength++;
}

template<class T>
void DynList<T>::pushBack(const T& element) {
	if (m_iLength + m_iStartIndex == m_iReservedLength) {
		reserve((m_iReservedLength * 4));
	}
	m_pArray[m_iStartIndex + m_iLength] = element;
	m_iLength++;
}

template<class T>
void DynList<T>::popFront() {
	m_iStartIndex++;
	m_iLength--;
}

template<class T>
void DynList<T>::popBack() {
	m_iLength--;
}

template<class T>
void DynList<T>::add(const T& _T, const unsigned int index) {
	if (m_iLength + m_iStartIndex == m_iReservedLength) {
		reserve((m_iReservedLength * 4));
	}
	T* pCopyArray = new T[m_iReservedLength];
	for (unsigned int i = 0; i < m_iLength; i++) {
		pCopyArray[i + m_iStartIndex] = m_pArray[i + m_iStartIndex];
	}
	pCopyArray[index + m_iStartIndex] = _T;
	m_iLength++;
	for (unsigned int i = index; i < m_iLength; i++) {
		pCopyArray[i + m_iStartIndex + 1] = m_pArray[i + m_iStartIndex];
	}
	delete[] m_pArray;
	m_pArray = pCopyArray;
}

template<class T>
void DynList<T>::remove(const unsigned int index) {
	T* pCopyArray = new T[m_iReservedLength];
	for (unsigned int i = 0; i < m_iLength; i++) {
		pCopyArray[i + m_iStartIndex] = m_pArray[i + m_iStartIndex];
	}
	for (unsigned int i = index; i < m_iLength - 1; i++) {
		pCopyArray[i + m_iStartIndex] = m_pArray[i + m_iStartIndex + 1];
	}
	delete[] m_pArray;
	m_pArray = pCopyArray;
	m_iLength--;
}

template<class T>
void DynList<T>::clear() {
	m_iLength = 0;
}

template<class T>
void DynList<T>::reserve(const unsigned int reservation) {
	m_iReservedLength += reservation;
	unsigned int newStartIndex = (reservation / 2) - (m_iLength / 2);
	T* pCopyArray = new T[m_iReservedLength];
	for (unsigned int i = 0; i < m_iLength; i++) {
		pCopyArray[i + newStartIndex] = m_pArray[i + m_iStartIndex];
	}
	delete[] m_pArray;
	m_pArray = pCopyArray;
	m_iStartIndex = newStartIndex;
}

template<class T>
T& DynList<T>::operator[](unsigned int index) const {
	return m_pArray[m_iStartIndex + index];
}
