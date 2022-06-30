#ifdef SOLUTION_01_8
#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 100'500

bool isVisited[MAX];
queue<int> q;
int N, K;
int result;

bool isValid(int x)
{
	return !(x < 0 || x > MAX) && false == isVisited[x];
}

int main()
{
	scanf("%d %d", &N, &K);

	q.push(N);

	while (false == q.empty())
	{
		size_t sz = q.size();
		for (size_t i = 0; i < sz; ++i)
		{
			int x = q.front();
			q.pop();

			if (x == K)
			{
				printf("%d", result);

				return 0;
			}

			isVisited[x] = true;

			if (isValid(x - 1))
				q.push(x - 1);
			if (isValid(x + 1))
				q.push(x + 1);
			if (isValid(2 * x))
				q.push(2 * x);
		}

		++result;
	}
}
#endif