#pragma once
using Rank = int;//��
template<typename T> class SeqList {
	const int DEFUALT_CAPACITY = 3;

public:
	//constuctor
	SeqList(int c = DEFUALT_CAPACITY, int s = 0, T v = 0) {
		//_capacity is c, _size is s, all the elements are initialized in v
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++]);
	}
	SeqList(const SeqList<T>& L) {
		//constuctor based on SeqList
		copyFrom(L._elem, 0, L._size);
	}
	SeqList(const T* A, Rank n) {
		//constructor based on array
		copyFrom(A, 0, n);
	}
	SeqList(const T* A, Rank lo, Rank hi) {
		//constructor based on array within the range of [lo, hi)
		copyFrom(A, lo, hi);
	}
	//Access
	int size() const { return _size; }
	int capacity() const { return _capacity; }
	bool empty() const { return !_size; }
	Rank find(const T& e, Rank lo, Rank hi) const;      //������������[lo,hi)����
	Rank find(const T& e) const { find(e, 0, _size); }  //��������ȫ�������
	Rank search(const T& e, Rank lo, Rank hi) const;    //������������[lo,hi)����
	Rank search(const T& e) const                       //��������ȫ�������
	{
		return (_size <= 0 ? -1 : search(e, 0, _size));
	}
	//����
	template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�
protected:
	T* _elem; int _size; int _capacity;
	void copyFrom(const T* A, Rank lo, Rank hi);
};

#include"SeqList_implementation.h"