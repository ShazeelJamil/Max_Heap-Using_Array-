#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include"LSLL.h"
template<typename T>
class MinHeap
{
	T* data;
	int maxNodes;
	int nodesCount;

	void displayDescendant(int);
	void swap(T& temp1, T& temp2);
	int getMinChild(int left, int right);
	bool isEmpty()
	{
		if (nodesCount > 0)
			return true;
		return false;
	}
public:
	void preOrder();
	MinHeap(int max);
	T getMin();
	void insert(T val);
	void removeMin();
	~MinHeap();
	LSLL<T> heapSort()
	{
		LSLL<T> sorted;
		while (nodesCount != 0)
		{
			sorted.insertAtTail(getMin());
			removeMin();
		}
		return sorted;
	}
};
#endif // !MIN_HEAP_H


