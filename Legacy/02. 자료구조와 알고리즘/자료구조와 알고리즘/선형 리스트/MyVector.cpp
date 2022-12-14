#include "MyVector.h"

#include <stdexcept>

MyVector::MyVector(size_t count)
	: _container{ new int[count] }, _size{ count }, _capacity{ count }
{
	for (size_t i = 0; i < _size; ++i)
	{
		_container[i] = 0;
	}
}

MyVector::MyVector(const MyVector& other)
	: _container{ new int[other._capacity] }, _size{ other._size }, _capacity{ other._capacity }
{
	for (size_t i = 0; i < _size; ++i)
	{
		_container[i] = other[i];
	}
}

MyVector& MyVector::operator=(const MyVector& rhs)
{
	if (this != &rhs)
	{
		MyVector temp(rhs);
		std::swap(_container, temp._container);
		std::swap(_size, temp._size);
		std::swap(_capacity, temp._capacity);
	}

	return *this;
}

MyVector::~MyVector()
{
	clear();
}

int* MyVector::begin()
{
	return _container;
}

const int* MyVector::begin() const
{
	return _container;
}

int* MyVector::end()
{
	return _container + _size;
}

const int* MyVector::end() const
{
	return _container + _size;
}

bool MyVector::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t MyVector::size() const
{
	return _size;
}

size_t MyVector::capacity() const
{
	return _capacity;
}

int& MyVector::at(size_t pos)
{
	if (pos >= _size)
	{
		throw std::out_of_range("Out of range");
	}

	return _container[pos];
}

const int& MyVector::at(size_t pos) const
{
	if (pos >= _size)
	{
		throw std::out_of_range("Out of range");
	}

	return _container[pos];
}

int& MyVector::operator[](size_t pos)
{
	return _container[pos];
}

const int& MyVector::operator[](size_t pos) const
{
	return _container[pos];
}

int& MyVector::front()
{
	return _container[0];
}

const int& MyVector::front() const
{
	return _container[0];
}

int& MyVector::back()
{
	return _container[_size - 1];
}

const int& MyVector::back() const
{
	return _container[_size - 1];
}

void MyVector::clear()
{
	delete[] _container;
	_container = nullptr;
	_size = 0;
	_capacity = 0;
}

int* MyVector::insert(int* pos, int value)
{
	int dist = pos - begin();

	if (_size == 0)
	{
		reserve(1);

		pos = begin() + dist;
	}
	else if (_size == _capacity)
	{
		reserve(_capacity * 2);

		pos = begin() + dist;
	}

	for (int* iter = end(); iter != pos; --iter)
	{
		*iter = *(iter - 1);
	}
	*pos = value;

	++_size;

	return pos;
}

int* MyVector::erase(int* pos)
{
	if (_size == 0)
	{
		return end();
	}

	int* last = end() - 1;
	for (int* iter = pos; iter != last; ++iter)
	{
		*iter = *(iter + 1);
	}

	--_size;

	return pos;
}

void MyVector::push_back(int value)
{
	insert(end(), value);
}

void MyVector::pop_back()
{
	erase(end() - 1);
}

bool MyVector::contains(int value)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (_container[i] == value)
		{
			return true;
		}
	}

	return false;
}

void MyVector::reserve(size_t newCapacity)
{
	if (_capacity >= newCapacity)
	{
		return;
	}

	int* newContainer = new int[newCapacity];

	for (size_t i = 0; i < _size; ++i)
	{
		newContainer[i] = _container[i];
	}

	delete[] _container;

	_container = newContainer;
	_capacity = newCapacity;
}
