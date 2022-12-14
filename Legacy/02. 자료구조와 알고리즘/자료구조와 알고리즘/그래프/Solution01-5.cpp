#ifdef SOLUTION_01_5
#include <stdio.h>

struct Pos
{
	int R = 0;
	int C = 0;
};

int N, M;
char map[128][128];
Pos Q[10000];
int front = 0;
int back = 0;
int costs[100][100];

void bfs()
{
	int dr[] = { -1, 1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };

	Q[back++] = { 0, 0 };
	costs[0][0] = 1;

	while (front != back)
	{
		Pos node = Q[front++];

		if (node.R == N - 1 && node.C == M - 1)
			break;

		for (int i = 0; i < 4; ++i)
		{
			int nr = dr[i] + node.R;
			int nc = dc[i] + node.C;

			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;

			if (map[nr][nc] != '1')
				continue;

			map[nr][nc] = '2';

			if (costs[nr][nc] == 0)
				costs[nr][nc] = costs[node.R][node.C] + 1;

			Q[back++] = { nr, nc };
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%s", map[i]);

	bfs();

	printf("%d", costs[N - 1][M - 1]);
}
#endif