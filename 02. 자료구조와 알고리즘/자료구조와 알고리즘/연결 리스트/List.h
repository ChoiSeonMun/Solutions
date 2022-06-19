#pragma once

#include <cstddef>

class List
{
public:
	struct Node
	{
		Node(int data = 0, Node* prev = nullptr, Node* next = nullptr);
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() = default;

		int		Data = 0;
		Node* Next = nullptr;
		Node* Prev = nullptr;
	};

public:
	class const_iterator
	{
	public:
		const_iterator(Node* p = nullptr);
		~const_iterator();

		const int& operator*() const;
		const int* operator->() const;

		const_iterator&		operator++();
		const_iterator		operator++(int);
		const_iterator&		operator--();
		const_iterator		operator--(int);

		bool				operator==(const const_iterator& rhs) const;
		bool				operator!=(const const_iterator& rhs) const;
		bool				operator==(nullptr_t p) const;
		bool				operator!=(nullptr_t p) const;

	public:
		Node* _p = nullptr;
	};

	class iterator : public const_iterator
	{
	public:
		using const_iterator::const_iterator;

		int& operator*() const;
		int* operator->() const;

		iterator& operator++();
		iterator		operator++(int);
		iterator& operator--();
		iterator		operator--(int);
	};

	// �⺻ ������
	List() = default;

	// count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
	explicit List(size_t count);

	// ���� ������.
	List(const List& other);

	// �Ҵ� ������
	List& operator=(const List& rhs);

	// �Ҹ���
	~List();

	// ù ��° ��Ҹ� ��ȯ�Ѵ�.
	int& front();
	const int& front() const;

	// ������ ��Ҹ� ��ȯ�Ѵ�.
	int& back();
	const int& back() const;

	// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	// ����Ʈ�� ����ִٸ� end()�� ����.
	iterator			begin();
	const_iterator		begin() const;

	// �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			end();
	const_iterator		end() const;

	// pos ������ value�� �����Ѵ�.
	// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			insert(iterator pos, int value);

	// pos ���� ��Ҹ� �����Ѵ�.
	// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	// �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
	iterator			erase(iterator pos);

	// ���ۿ� value�� �����Ѵ�.
	void			push_front(int value);

	// ���� value�� �����Ѵ�.
	void			push_back(int value);

	// ���� ��Ҹ� �����Ѵ�.
	void			pop_front();

	// �� ��Ҹ� �����Ѵ�.
	void			pop_back();

	// �����̳ʰ� ������� �Ǵ��Ѵ�.
	bool			empty() const;

	// ����Ʈ �ȿ� �ִ� ����� ������ ��ȯ�Ѵ�.
	size_t			size() const;

	// �����̳ʸ� ���������.
	void			clear();

	// �ش� value�� �ִ��� üũ�Ѵ�.
	bool			contains(int value) const;
private:
	Node* _end = new Node();
	Node* _head = _end;
	size_t			_size = 0;
};