#ifdef SOLUTION_01_1
#include <iostream>
#include <list>
#include <string>

using namespace std;

string s;
int M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;

	list<char> lst(s.begin(), s.end());
	cin >> M;

	auto iter = lst.end();

	for (int i = 0; i < M; ++i)
	{
		char op = '\0';
		cin >> op;

		switch (op)
		{
		case 'L':
			if (iter != lst.begin())
				--iter;
			break;
		case 'D':
		{
			if (iter != lst.end())
				++iter;
		}
		break;
		case 'B':
			if (iter != lst.begin())
			{
				--iter;

				iter = lst.erase(iter);
			}
			break;
		case 'P':
		{
			char param = '\0';
			cin >> param;

			iter = lst.insert(iter, param);
			++iter;
		}
		break;
		}
	}

	for (char ch : lst)
		cout << ch;

}
#endif