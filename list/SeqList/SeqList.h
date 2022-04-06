#pragma once
using Rank = int;//秩
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
	Rank find(const T& e, Rank lo, Rank hi) const;      //无序向量区间[lo,hi)查找
	Rank find(const T& e) const { find(e, 0, _size); }  //无序向量全区间查找
	Rank search(const T& e, Rank lo, Rank hi) const;    //有序向量区间[lo,hi)查找
	Rank search(const T& e) const                       //有序向量全区间查找
	{
		return (_size <= 0 ? -1 : search(e, 0, _size));
	}
	//遍历
	template <typename VST> void traverse(VST&); //遍历（使用函数对象，可全局性修改）
protected:
	T* _elem; int _size; int _capacity;
	void copyFrom(const T* A, Rank lo, Rank hi);
};

#include"SeqList_implementation.h"