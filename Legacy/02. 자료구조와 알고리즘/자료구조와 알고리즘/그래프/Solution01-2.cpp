#ifdef SOLUTION_01_2
#include <stdio.h>

int N, M;
bool graph[101][101];
int result;
bool isVisited[101];

void dfs(int node)
{
	isVisited[node] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (false == isVisited[i] && graph[node][i])
			dfs(i);
	}

	++result;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		graph[s][e] = true;
		graph[e][s] = true;
	}

	dfs(1);

	printf("%d", result - 1);
}
#endif