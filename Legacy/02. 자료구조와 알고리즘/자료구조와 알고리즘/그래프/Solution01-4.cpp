#ifdef SOLUTION_01_4
#include <stdio.h>
#include <memory.h>

int T;
int M, N, K;
bool map[50][50];
bool isVisited[50][50];

void dfs(int r, int c)
{
	static int dr[] = { -1, 1, 0, 0 };
	static int dc[] = { 0, 0, -1, 1 };

	isVisited[r][c] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nr = dr[i] + r;
		int nc = dc[i] + c;

		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;

		if (isVisited[nr][nc] || false == map[nr][nc])
			continue;

		dfs(nr, nc);
	}
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%d %d %d", &M, &N, &K);
		for (int k = 0; k < K; ++k)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			map[y][x] = true;
		}

		int result = 0;

		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (false == isVisited[r][c] && map[r][c])
				{
					dfs(r, c);

					++result;
				}
			}
		}

		printf("%d\n", result);

		memset(map, false, sizeof(map));
		memset(isVisited, false, sizeof(isVisited));
	}
}
#endif