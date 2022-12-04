#ifndef MAX_HEAP_H
#define MAX_HEAP_H


template <typename T>
class MaxHeap
{
	T* data;
	int maxNodes;
	int nodesCount;

	void displayDescendant(int);
	void swap(T& temp1, T& temp2);
	int getMaxChild(int left, int right);
public:
	void preOrder();
	MaxHeap(int max);
	~MaxHeap();
	T getMax();
	void insert(T val);
	void removeMax();
};
#endif // !MAX_HEAP_H



