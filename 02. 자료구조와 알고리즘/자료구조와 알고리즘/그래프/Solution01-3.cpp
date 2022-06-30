#ifdef SOLUTION_01_3
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char map[25][25];
bool isVisited[25][25];
int ans;
vector<int> vec;

int dfs(int r, int c)
{
	static int dr[] = { -1, 1, 0, 0 };
	static int dc[] = { 0, 0, -1, 1 };

	isVisited[r][c] = true;
	int result = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nr = dr[i] + r;
		int nc = dc[i] + c;

		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;

		if (isVisited[nr][nc] || map[nr][nc] != '1')
			continue;

		result += dfs(nr, nc);
	}

	return result;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s", map[i]);

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (false == isVisited[r][c] && map[r][c] == '1')
			{
				vec.push_back(dfs(r, c));

				++ans;
			}
		}
	}
	sort(vec.begin(), vec.end());

	printf("%d\n", ans);
	for (int elem : vec)
		printf("%d\n", elem);
}
#endif