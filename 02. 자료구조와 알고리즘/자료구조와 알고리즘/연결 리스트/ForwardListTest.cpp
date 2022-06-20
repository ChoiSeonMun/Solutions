#ifdef FORWARD_LIST_TEST
#include <iostream>
#include <forward_list>

#include "ForwardList.h"

using namespace std;

int main()
{
	forward_list<int> list;
	forward_list<int> list2(5);

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.pop_front();

	cout << list.front() << endl;

	for (int elem : list)
	{
		cout << elem << ' ';
	}
	cout << endl;

	auto iter = list2.insert_after(list2.begin(), 3);
	++iter;
	iter = list2.insert_after(iter, 4);
	list2.erase_after(iter);

	for (int elem : list2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << list2.empty() << endl;

	forward_list<int> list3(list);

	for (int elem : list)
	{
		cout << elem << ' ';
	}
	cout << endl;

	ForwardList mlist;
	ForwardList mlist2(5);

	mlist.push_front(1);
	mlist.push_front(2);
	mlist.push_front(3);
	mlist.pop_front();

	cout << mlist.front() << endl;

	for (int elem : mlist)
	{
		cout << elem << ' ';
	}
	cout << endl;

	auto iter2 = mlist2.insert_after(mlist2.begin(), 3);
	++iter2;
	iter2 = mlist2.insert_after(iter2, 4);
	mlist2.erase_after(iter2);

	for (int elem : mlist2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << mlist2.empty() << endl;

	ForwardList mlist3(mlist);

	for (int elem : mlist3)
	{
		cout << elem << ' ';
	}
	cout << endl;
}
#endif