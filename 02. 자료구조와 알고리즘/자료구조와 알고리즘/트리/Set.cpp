#include "Set.h"

#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	: Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::~Set()
{
	clear();

	delete _head;
	_head = nullptr;
}

int Set::height() const
{
	std::queue<Node*> q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	int height = -1;
	while (false == q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			Node* node = q.front();
			q.pop();

			if (node->Left)
			{
				q.push(node->Left);
			}

			if (node->Right)
			{
				q.push(node->Right);
			}
		}

		++height;
	}

	return height;
}

int Set::height2() const
{
	if (_head->Parent == nullptr)
	{
		return -1;
	}

	return heightHelper(_head->Parent);
}

int Set::heightHelper(Node* node) const
{
	int height = 0;

	if (node->Left)
	{
		height = 1 + heightHelper(node->Left);
	}

	if (node->Right)
	{
		height = std::max(height, 1 + heightHelper(node->Right));
	}

	return height;
}

bool Set::empty() const
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

size_t Set::size() const
{
	return _size;
}

void Set::clear()
{
	while (false == empty())
	{
		erase(_head->Parent);
	}
}

bool Set::insert(int value)
{
	Node* newNode = new Node(value);

	if (_head->Parent == nullptr)
	{
		_head->Parent = newNode;
		newNode->Parent = _head;

		++_size;

		return true;
	}

	Node* parent = nullptr;
	Node* p = _head->Parent;

	while (p)
	{
		parent = p;

		if (p->Data == value)
		{
			return false;
		}
		else if (value < p->Data)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}

	if (value < parent->Data)
	{
		parent->Left = newNode;
	}
	else
	{
		parent->Right = newNode;
	}
	newNode->Parent = parent;

	++_size;

	return true;
}

void Set::erase(int value)
{
	Node* removedNode = find(value);
	if (removedNode == nullptr)
	{
		return;
	}

	erase(removedNode);
}

void Set::erase(Node* pos)
{
	if (pos->Left && pos->Right)
	{
		Node* successor = pos->Right;
		while (successor->Left)
		{
			successor = successor->Left;
		}

		pos->Data = successor->Data;

		erase(successor);

		return;
	}

	Node** child = nullptr;
	if (pos == _head->Parent)
	{
		child = &_head->Parent;
	}
	else if (pos->Data < pos->Parent->Data)
	{
		child = &pos->Parent->Left;
	}
	else
	{
		child = &pos->Parent->Right;
	}

	*child = nullptr;
	if (pos->Left)
	{
		*child = pos->Left;
		pos->Left->Parent = pos->Parent;
	}
	else if (pos->Right)
	{
		*child = pos->Right;
		pos->Right->Parent = pos->Parent;
	}

	delete pos;
	pos = nullptr;

	--_size;
}

Set::Node* Set::find(int value) const
{
	Node* result = _head->Parent;

	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if (result->Data < value)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}

	return result;
}

void Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}

void Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}

void Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}

void Set::traverseByLevelorder() const
{
	std::queue<Node*> q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	while (false == q.empty())
	{
		Node* node = q.front();
		q.pop();

		std::cout << node->Data << "->";

		if (node->Left)
		{
			q.push(node->Left);
		}

		if (node->Right)
		{
			q.push(node->Right);
		}
	}
}

void Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}

void Set::traverseByInorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}

	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}

void Set::traverseByPostorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}

	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}
