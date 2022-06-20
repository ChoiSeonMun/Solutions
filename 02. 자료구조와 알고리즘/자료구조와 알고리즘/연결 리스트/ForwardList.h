#pragma once

#include <cstddef>

class ForwardList
{
	struct Node
	{
		Node(int data = 0, Node* next = nullptr);
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node();

		int		Data = 0;
		Node* Next = nullptr;
	};

public:
	class const_iterator
	{
	public:
		const_iterator(Node* p = nullptr);
		~const_iterator();

		const int& operator*() const;
		const int* operator->() const;
		const_iterator& operator++();
		const_iterator		operator++(int);
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
	};

	// 기본 생성자
	ForwardList();

	// count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
	explicit ForwardList(size_t count);

	// 복사 생성자.
	ForwardList(const ForwardList& other);

	// 할당 연산자
	ForwardList& operator=(const ForwardList& rhs);

	// 소멸자
	~ForwardList();

	// 첫 번째 요소를 반환한다.
	int& front();
	const int& front() const;

	// 시작 전 요소를 가리키는 반복자를 반환한다.
	iterator			before_begin();
	const_iterator		before_begin() const;

	// 시작 요소를 가리키는 반복자를 반환한다.
	iterator			begin();
	const_iterator		begin() const;

	// 끝 다음 요소를 가리키는 반복자를 반환한다.
	iterator			end();
	const_iterator		end() const;

	// pos 다음에 value를 삽입한다.
	// 삽입된 요소를 가리키는 반복자를 반환한다.
	iterator			insert_after(const_iterator pos, int value);

	// pos 다음 요소를 삭제한다.
	// 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
	// 아무 요소도 없으면 end()를 반환한다.
	iterator			erase_after(const_iterator pos);

	// 시작 요소에 value를 삽입한다.
	void				push_front(int value);

	// 시작 요소를 제거한다.
	void				pop_front();

	// 컨테이너가 비었는지 판단한다.
	bool				empty() const;

	// 컨테이너를 비워버린다.
	void				clear();

	// value가 있는지 검사한다.
	bool				contains(int value) const;
private:
	Node* _head = new Node();
};