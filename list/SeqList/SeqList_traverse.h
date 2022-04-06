#pragma once
template <typename T> template <typename VST> //元素类型、操作器
void SeqList<T>::traverse(VST& visit) //借助函数对象机制
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
} //遍历向量