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
	// 1. ���� ���� �������� �����͸� �����Ѵ�.
	_container.push_back(value);

	// 2. ���� �Һ����� ������ ������ ��ġ�� �ٲ��ش�.
	size_t currentIndex = size();
	while (1 < currentIndex)
	{
		size_t parentIndex = currentIndex / 2;

		// HACK : ��� ���Ǽ��� ���� �ε����� 0���Ͱ� �ƴ�
		// 1���� �����ϰ� �����Ƿ�
		// ���� �����Ϳ� �����Ϸ��� 1�� ����� �Ѵ�.
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
	// 1. ������ �����͸� ��Ʈ ��忡 �����Ѵ�.
	_container[0] = _container.back();

	// 2. ������ ��Ҹ� �����Ѵ�.
	_container.pop_back();

	// 3. ���� �Һ����� ������ ������ ��ġ�� �ٲ��ش�.
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

		// 3-1. �ٲ� �ڽ��� �����Ѵ�.
		size_t child = left;
		if (right <= currentSize && _container[left - 1] < _container[right - 1])
		{
			child = right;
		}

		// 3-2. �ٲ� �ڽ��� ���ٸ� �����Ѵ�.
		if (_container[currentIndex - 1] >= _container[child - 1])
		{
			break;
		}

		std::swap(_container[currentIndex - 1], _container[child - 1]);
		currentIndex = child;
	}
}