#ifdef MYVECTOR_TEST
#include <vector>
#include <iostream>

#include "MyVector.h"

using namespace std;

int main()
{
	vector<int> vec;
	vector<int> vec2(5);
	vector<int> vec3 = { 1, 2, 3, 4, 5 };

	vec.push_back(1);
	vec.push_back(2);
	vec.pop_back();

	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i];
	}
	cout << endl;

	try
	{
		vec.at(1);
	}
	catch (std::out_of_range& e)
	{
		cout << e.what() << endl;
	}

	vec.pop_back();

	cout << boolalpha << vec.empty() << endl;

	cout << "Cap : " << vec.capacity() << endl;
	vec.reserve(10);
	cout << "New Cap : " << vec.capacity() << endl;

	vec2.insert(vec2.begin() + 2, 3);
	for (size_t elem : vec2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	vec3.erase(vec3.begin());
	for (size_t i = 0; i < vec3.size(); ++i)
	{
		cout << vec3[i] << ' ';
	}
	cout << endl;

	MyVector mvec;
	MyVector mvec2(5);

	mvec.push_back(1);
	mvec.push_back(2);
	mvec.pop_back();

	for (size_t i = 0; i < mvec.size(); ++i)
	{
		cout << mvec[i];
	}
	cout << endl;

	try
	{
		mvec.at(1);
	}
	catch (std::out_of_range& e)
	{
		cout << e.what() << endl;
	}

	mvec.pop_back();

	cout << boolalpha << mvec.empty() << endl;

	cout << "Cap : " << mvec.capacity() << endl;
	mvec.reserve(10);
	cout << "New Cap : " << mvec.capacity() << endl;

	mvec2.insert(mvec2.begin() + 2, 3);
	for (int elem : mvec2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << mvec2.contains(2) << endl;

	mvec2.erase(mvec2.begin());
	for (size_t i = 0; i < mvec2.size(); ++i)
	{
		cout << vec2[i] << ' ';
	}
	cout << endl;
}
#endif