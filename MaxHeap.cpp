#include "MaxHeap.h"

#include "MinHeap.h"
#include<iostream>
using namespace std;

template <typename T>
MaxHeap<T>::MaxHeap(int max)
{
	if (max <= 0)
		max = 10;
	data = new T[max];
	maxNodes = max;
	nodesCount = 0;
}
template <typename T>
void MaxHeap<T>::insert(T val)
{
	if (nodesCount == maxNodes)
		return;
	int cur = nodesCount;
	data[nodesCount++] = val;
	while (cur != 0 && (data[cur] > data[(cur - 1) / 2]))
	{
		swap(data[cur], data[(cur - 1) / 2]);
		cur = (cur - 1) / 2;
	}
}
template <typename T>
T MaxHeap<T>::getMax()
{
	if (!nodesCount)
		throw string("Heap is empty\n");
	return data[0];
}
template<typename T>
MaxHeap<T>::~MaxHeap()
{
	if (data)
		delete[]data;
	data = nullptr;
	maxNodes = nodesCount = 0;
}
template<typename T>
int MaxHeap<T>::getMaxChild(int left, int right)
{
	return data[left] > data[right] ? left : right;
}
template<typename T>
void MaxHeap<T>::removeMax()
{
	if (nodesCount == 0)
		return;
	else if (nodesCount == 1)
	{
		nodesCount--;
		return;
	}
	nodesCount--;
	data[0] = data[nodesCount];
	int cur = 0;
	int left = cur * 2 + 1;
	int right;
	while (left < nodesCount)
	{
		int maxIndex;
		right = cur * 2 + 2;
		if (right < nodesCount)
			maxIndex = getMaxChild(left, right);
		else
			maxIndex = left;
		if (data[cur] < data[maxIndex])
		{
			swap(data[cur], data[maxIndex]);
			cur = maxIndex;
		}
		else
			return;
		left = cur * 2 + 1;
	}
}
template<typename T>
void MaxHeap<T>::swap(T& temp1, T& temp2)
{
	T temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}

template<typename T>
void MaxHeap<T>::preOrder()
{
	if (!nodesCount)
		return;
	displayDescendant(0);
}
template<typename T>
void MaxHeap<T>::displayDescendant(int index)
{

	cout << data[index] << " ";
	if (index * 2 + 1 < nodesCount)
		displayDescendant(2 * index + 1);
	if (index * 2 + 2 < nodesCount)
		displayDescendant(2 * index + 2);
}
