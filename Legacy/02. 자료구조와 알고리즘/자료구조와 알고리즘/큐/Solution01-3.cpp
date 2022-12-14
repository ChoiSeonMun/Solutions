#ifdef SOLUTION_01_3
#include <stdio.h>

int N, K;

int sol[1000];
int si = 0;

bool q[1000];

int main()
{
	scanf("%d %d", &N, &K);

	int p = -1;
	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < K; ++k)
		{
			do
			{
				p = (p + 1) % N;
			} while (q[p]);
		}

		q[p] = true;
		sol[si++] = p + 1;
	}

	printf("<");
	for (int i = 0; i < si - 1; ++i)
		printf("%d, ", sol[i]);
	printf("%d>", sol[si - 1]);

}
#endif