#include "Heap.h"
#include <algorithm>

const int& Heap::top() const
{
	return _container.front();
}

bool Heap::empty() const
{
	return _container.empty();
}

size_t Heap::size() const
{
	return _container.size();
}

void Heap::push(int value)
{
	// 1. 힙의 가장 마지막에 데이터를 삽입한다.
	_container.push_back(value);

	// 2. 힙의 불변성을 만족할 때까지 위치를 바꿔준다.
	size_t currentIndex = size();
	while (1 < currentIndex)
	{
		size_t parentIndex = currentIndex / 2;

		// HACK : 계산 편의성을 위해 인덱스를 0부터가 아닌
		// 1부터 시작하게 했으므로
		// 실제 데이터에 접근하려면 1을 빼줘야 한다.
		if (_container[parentIndex - 1] >= _container[currentIndex - 1])
		{
			break;
		}

		std::swap(_container[parentIndex - 1], _container[currentIndex - 1]);
		currentIndex = parentIndex;
	}
}

void Heap::pop()
{
	// 1. 마지막 데이터를 루트 노드에 삽입한다.
	_container[0] = _container.back();

	// 2. 마지막 요소를 제거한다.
	_container.pop_back();

	// 3. 힙의 불변성을 만족할 때까지 위치를 바꿔준다.
	const size_t currentSize = _container.size();
	size_t currentIndex = 1;
	while (true)
	{
		size_t left = currentIndex * 2;
		size_t right = left + 1;

		if (left > currentSize)
		{
			break;
		}

		// 3-1. 바꿀 자식을 선택한다.
		size_t child = left;
		if (right <= currentSize && _container[left - 1] < _container[right - 1])
		{
			child = right;
		}

		// 3-2. 바꿀 자식이 없다면 종료한다.
		if (_container[currentIndex - 1] >= _container[child - 1])
		{
			break;
		}

		std::swap(_container[currentIndex - 1], _container[child - 1]);
		currentIndex = child;
	}
}