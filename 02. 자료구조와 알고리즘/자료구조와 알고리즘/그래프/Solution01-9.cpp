#ifdef SOLUTION_01_9
#include <stdio.h>
#include <memory.h>

using namespace std;

#define Q_SIZE (1 << 15)

int T, I;
int costs[300][300];
struct { int R = 0; int C = 0; } Q[Q_SIZE], s, e;
int f, b;

void Push(int r, int c)
{
	Q[b] = { r, c };
	b = (b + 1) % Q_SIZE;
}

void Pop(int& r, int& c)
{
	r = Q[f].R;
	c = Q[f].C;

	f = (f + 1) % Q_SIZE;
}

int bfs()
{
	static int dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	static int dc[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	f = b = 0;
	Push(s.R, s.C);

	while (f != b)
	{
		int r, c;
		Pop(r, c);

		if (r == e.R && c == e.C)
			return costs[r][c];

		for (int i = 0; i < 8; ++i)
		{
			int nr = dr[i] + r;
			int nc = dc[i] + c;

			if (nr < 0 || nr >= I || nc < 0 || nc >= I)
				continue;

			if (nr == s.R && nc == s.C)
				continue;

			if (costs[nr][nc] != 0)
				continue;

			costs[nr][nc] = costs[r][c] + 1;
			Push(nr, nc);
		}
	}

	return 0;
}

int main()
{
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		scanf("%d", &I);
		scanf("%d %d", &s.R, &s.C);
		scanf("%d %d", &e.R, &e.C);

		printf("%d\n", bfs());

		memset(costs, 0, sizeof(costs));
	}
}
#endif