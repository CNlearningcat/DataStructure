#pragma once
template<typename T>
void SeqList<T>::copyFrom(const T* A, Rank lo, Rank hi) {
	_elem = new T[2 * (hi - lo)];
	for (_size = 0; lo < hi; ++_size, ++lo)
		_elem[_size] = A[lo];
}