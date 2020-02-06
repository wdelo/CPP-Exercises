#pragma once

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
	T& operator[](unsigned int index) const;

private:
	T* m_pArray;
	unsigned int m_iLength;
	unsigned int m_iReservedLength;
	unsigned int m_iStartIndex;
};



