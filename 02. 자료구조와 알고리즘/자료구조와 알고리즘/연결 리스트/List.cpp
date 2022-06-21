#include "List.h"

#include <utility>

List::Node::Node(int data, Node* prev, Node* next)
	: Data{ data }, Next{ next }, Prev{ prev }
{

}

List::const_iterator::const_iterator(Node* p)
	: _p{ p }
{

}

List::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& List::const_iterator::operator*() const
{
	return _p->Data;
}

const int* List::const_iterator::operator->() const
{
	return &_p->Data;
}

List::const_iterator& List::const_iterator::operator++()
{
	_p = _p->Next;
	
	return *this;
}

List::const_iterator List::const_iterator::operator++(int)
{
	auto temp = *this;
	_p = _p->Next;

	return temp;
}

List::const_iterator& List::const_iterator::operator--()
{
	_p = _p->Prev;
	
	return *this;
}

List::const_iterator List::const_iterator::operator--(int)
{
	auto temp = *this;
	_p = _p->Prev;

	return temp;
}

bool List::const_iterator::operator==(const const_iterator& rhs) const
{
	return _p == rhs._p;
}

bool List::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool List::const_iterator::operator==(nullptr_t p) const
{
	return _p == nullptr;
}

bool List::const_iterator::operator!=(nullptr_t p) const
{
	return _p != nullptr;
}

int& List::iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* List::iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

List::iterator& List::iterator::operator++()
{
	const_iterator::operator++();

	return *this;
}

List::iterator List::iterator::operator++(int)
{
	auto temp = *this;
	const_iterator::operator++();

	return temp;
}

List::iterator& List::iterator::operator--()
{
	const_iterator::operator--();

	return *this;
}

List::iterator List::iterator::operator--(int)
{
	auto temp = *this;
	const_iterator::operator--();

	return temp;
}

List::List()
{
	_end->Next = _end;
	_end->Prev = _end;
}

List::List(size_t count)
	: List()
{
	for (size_t i = 0; i < count; ++i)
	{
		push_front(0);
	}
}

List::List(const List& other)
	: List()
{
	for (auto iter = other.begin(); iter != other.end(); ++iter)
	{
		push_back(*iter);
	}
}

List& List::operator=(const List& rhs)
{
	if (this != &rhs)
	{
		List temp(rhs);
		std::swap(_end, temp._end);
		std::swap(_size, temp._size);
	}

	return *this;
}

List::~List()
{
	clear();

	delete _end;
	_end = nullptr;
}

int& List::front()
{
	return *begin();
}

const int& List::front() const
{
	return *begin();
}

int& List::back()
{
	return *(--end());
}

const int& List::back() const
{
	return *(--end());
}

List::iterator List::begin()
{
	return iterator(_end->Next);
}

List::const_iterator List::begin() const
{
	return const_iterator(_end->Next);
}

List::iterator List::end()
{
	return iterator(_end);
}

List::const_iterator List::end() const
{
	return const_iterator(_end);
}

List::iterator List::insert(iterator pos, int value)
{
	Node* nextNode = pos._p;
	Node* prevNode = pos._p->Prev;
	Node* newNode = new Node(value, prevNode, nextNode);

	prevNode->Next = newNode;
	nextNode->Prev = newNode;

	++_size;

	return newNode;
}

List::iterator List::erase(iterator pos)
{
	Node* removed = pos._p;
	Node* removedPrev = removed->Prev;
	Node* removedNext = removed->Next;

	removedPrev->Next = removedNext;
	removedNext->Prev = removedPrev;

	delete removed;

	--_size;

	return removedNext;
}

void List::push_front(int value)
{
	insert(begin(), value);
}

void List::push_back(int value)
{
	insert(end(), value);
}

void List::pop_front()
{
	erase(begin());
}

void List::pop_back()
{
	erase(--end());
}

bool List::empty() const
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

size_t List::size() const
{
	return _size;
}

void List::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

bool List::contains(int value) const
{
	for (auto iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}
