#include "MinHeap.h"
#include<iostream>
using namespace std;

template <typename T>
MinHeap<T>::MinHeap(int max)
{
	if (max <= 0)
		max = 10;
	data = new T[max];
	maxNodes = max;
	nodesCount = 0;
}
template <typename T>
void MinHeap<T>::insert(T val)
{
	if (nodesCount == maxNodes)
		return;
	int cur = nodesCount;
	data[nodesCount++] = val;
	while (cur != 0 && (data[cur] < data[(cur - 1) / 2]))
	{
		swap(data[cur], data[(cur - 1) / 2]);
		cur = (cur - 1) / 2;
	}
}
template <typename T>
T MinHeap<T>::getMin()
{
	if (!nodesCount)
		throw string("Heap is empty\n");
	return data[0];
}
template<typename T>
MinHeap<T>::~MinHeap()
{
	if (data)
		delete[]data;
	data = nullptr;
	maxNodes = nodesCount = 0;
}
template<typename T>
int MinHeap<T>:: getMinChild(int left, int right)
{
	return data[left] < data[right] ? left : right;
}
template<typename T>
void MinHeap<T>::removeMin()
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
		int minIndex;
		right = cur * 2 + 2;
		if (right < nodesCount)
			minIndex = getMinChild(left, right);
		else
			minIndex = left;
		if (data[cur] > data[minIndex])
		{
			swap(data[cur], data[minIndex]);
			cur = minIndex;
		}
		else
			return;
		left = cur * 2 + 1;
	}
}
template<typename T>
void MinHeap<T>:: swap(T& temp1, T& temp2)
{
	T temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}

template<typename T>
void MinHeap<T>::preOrder()
{
	if (!nodesCount)
		return;
	displayDescendant(0);
}
template<typename T>
void MinHeap<T>::displayDescendant(int index)
{
	
	cout << data[index] << " ";
	if (index * 2 + 1 < nodesCount)
		displayDescendant(2 * index + 1);
	if (index * 2 + 2 < nodesCount)
		displayDescendant(2 * index + 2);
}
