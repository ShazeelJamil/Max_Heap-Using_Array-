#include<iostream>
using namespace std;
#include"MinHeap.h"
#include"MaxHeap.h"
template <typename T>
void heapSortAscending(T* arr, int size);
template <typename T>
void heapSortDescending(T* arr, int size);

int main()
{
	//int arr[10] = { 65,-876,435,32,9868,34,757,7,0, 10 };
	//heapSortDescending(arr,10);
	/*for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';*/

	MinHeap<int> q(10);
	q.insert(3);
	q.insert(4);
	q.insert(5);
	q.insert(7);

	LSLL<int> temp = q.heapSort();
	temp.display();
	//q.preOrder();

	return 0;
}
template <typename T>
void heapSortAscending(T* arr, int size)
{
	if (size < 2)
		return;
	MinHeap<T> min(size);
	for (int i = 0; i < size; i++)
		min.insert(arr[i]);
	for (int i = 0; i < size; i++)
	{
		arr[i] = min.getMin();
		min.removeMin();
	}
}
template <typename T>
void heapSortDescending(T* arr, int size)
{
	if (size < 2)
		return;
	MaxHeap<T> max(size);
	for (int i = 0; i < size; i++)
		max.insert(arr[i]);
	for (int i = 0; i < size; i++)
	{
		arr[i] = max.getMax();
		max.removeMax();
	}
}


