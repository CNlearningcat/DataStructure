#pragma once
template<typename T> //����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo-1
Rank SeqList<T>::find(const T& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi])); //ʼ������С[lo,hi)��lo = hi�ǲ�����ѭ��������hi���һ����Ϊlo-1
	return hi;
}