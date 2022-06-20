#include "ForwardList.h"

#include <utility>

ForwardList::ForwardList()
{
}

ForwardList::ForwardList(size_t count)
	: ForwardList()
{
	for (size_t i = 0; i < count; ++i)
	{
		insert_after(before_begin(), 0);
	}
}

ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	auto inserted = before_begin();
	for (auto elem : other)
	{
		inserted = insert_after(inserted, elem);
	}
}

ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (this != &rhs)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
	}

	return *this;
}

ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;
}

int& ForwardList::front()
{
	return *begin();
}

const int& ForwardList::front() const
{
	return *begin();
}

ForwardList::iterator ForwardList::before_begin()
{
	return iterator(_head);
}

ForwardList::const_iterator ForwardList::before_begin() const
{
	return const_iterator(_head);
}

ForwardList::iterator ForwardList::begin()
{
	auto r = before_begin();
	++r;

	return r;
}

ForwardList::const_iterator ForwardList::begin() const
{
	auto r = before_begin();
	++r;

	return r;
}

ForwardList::iterator ForwardList::end()
{
	return iterator(nullptr);
}

ForwardList::const_iterator ForwardList::end() const
{
	return const_iterator(nullptr);
}

ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	Node* where = pos._p;
	Node* newNode = new Node(value);
	newNode->Next = where->Next;
	where->Next = newNode;

	return iterator(newNode);
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	Node* where = pos._p;
	Node* removed = where->Next;

	where->Next = removed->Next;
	delete removed;

	return where->Next;
}

void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void ForwardList::pop_front()
{
	erase_after(before_begin());
}

bool ForwardList::empty() const
{
	if (begin() == end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ForwardList::clear()
{
	while (false == empty())
	{
		erase_after(before_begin());
	}
}

bool ForwardList::contains(int value) const
{
	return false;
}

ForwardList::Node::Node(int data, Node* next)
	: Data{ data }, Next{ next }
{
}

ForwardList::Node::~Node()
{
	Next = nullptr;
}

ForwardList::const_iterator::const_iterator(Node* p)
	: _p{ p }
{
}

ForwardList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& ForwardList::const_iterator::operator*() const
{
	return _p->Data;
}

const int* ForwardList::const_iterator::operator->() const
{
	return &(_p->Data);
}

ForwardList::const_iterator& ForwardList::const_iterator::operator++()
{
	_p = _p->Next;

	return *this;
}

ForwardList::const_iterator ForwardList::const_iterator::operator++(int)
{
	auto temp = *this;
	_p = _p->Next;

	return temp;
}

bool ForwardList::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool ForwardList::const_iterator::operator==(nullptr_t p) const
{
	if (_p == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == nullptr);
}

int& ForwardList::iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* ForwardList::iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

ForwardList::iterator& ForwardList::iterator::operator++()
{
	const_iterator::operator++();

	return *this;
}

ForwardList::iterator ForwardList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();

	return temp;
}