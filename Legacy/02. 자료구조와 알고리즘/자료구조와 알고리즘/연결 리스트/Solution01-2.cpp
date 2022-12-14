#ifdef SOLUTION_01_2
#include <stdio.h>
#include <list>

using namespace std;

int T;
char keys[1'000'001];

int main()
{
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		scanf("%s", keys);

		list<char> lst;
		auto iter = lst.begin();

		for (const char* ch = keys; *ch != '\0'; ++ch)
		{
			switch (*ch)
			{
			case '-':
				if (iter != lst.begin())
				{
					--iter;
					iter = lst.erase(iter);
				}
				break;
			case '<':
				if (iter != lst.begin())
					--iter;
				break;
			case '>':
				if (iter != lst.end())
					++iter;
				break;
			default:
				iter = lst.insert(iter, *ch);
				++iter;
				break;
			}
		}

		for (char ch : lst)
			printf("%c", ch);
		puts("");
	}
}
#endif