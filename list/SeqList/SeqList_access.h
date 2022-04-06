#pragma once
template<typename T> //无序向量的顺序查找：返回最后一个元素e的位置；失败时，返回lo-1
Rank SeqList<T>::find(const T& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi])); //始终在缩小[lo,hi)，lo = hi是不满足循环，跳出hi会减一，即为lo-1
	return hi;
}