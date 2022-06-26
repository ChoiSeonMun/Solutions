#ifdef SOLUTION_01_5
#include <stdio.h>
#include <algorithm>

int N, C;
int x[200'000];

int count(int d)
{
	int c = 1;
	int p = 0;

	for (int i = 1; i < N; ++i)
	{
		if (x[i] - x[p] >= d)
		{
			++c;
			p = i;
		}
	}

	return c;
}

int ps()
{
	int s = 1, e = x[N - 1] + 1;

	int result = 0;

	while (s < e)
	{
		int m = (s + e) / 2;
		int c = count(m);

		if (c >= C)
		{
			result = (result < m) ? m : result;

			s = m + 1;
		}
		else
			e = m;
	}

	return result;
}

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; ++i)
		scanf("%d", &x[i]);

	std::sort(x, x + N);

	printf("%d", ps());
}
#endif