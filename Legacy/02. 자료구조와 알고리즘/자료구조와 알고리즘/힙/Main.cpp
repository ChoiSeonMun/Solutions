#include <iostream>

#include "Heap.h"

int main()
{
	Heap heap;

	for (int num : { 3, 10, 2, 4, 6, 8 })
	{
		heap.push(num);
	}

	while (false == heap.empty())
	{
		std::cout << heap.top() << ' ';
		heap.pop();
	}
}