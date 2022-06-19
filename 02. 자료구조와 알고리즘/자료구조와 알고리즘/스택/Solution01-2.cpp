#ifdef SOLUTION_01_2
#include <stdio.h>

int K;

int st[100'000];
int top = -1;

int main()
{
	scanf("%d", &K);

	for (int i = 0; i < K; ++i)
	{
		int num = 0;
		scanf("%d", &num);

		if (num == 0)
			--top;
		else
			st[++top] = num;
	}

	int sum = 0;

	for (int i = 0; i <= top; ++i)
		sum += st[i];

	printf("%d", sum);
}
#endif