#ifdef SOLUTION_01_6
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int M, N;
int box[1000][1000];
enum { EMPTY = -1, TOMATO, RIPENED };

using Coord = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. M, N을 입력 받는다.
    cin >> M >> N;

    // 2. 토마토 상자의 정보를 입력 받는다.
    queue<Coord> q;
    int tomatoCount = 0;
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < M; ++c)
        {
            cin >> box[r][c];

            if (box[r][c] == RIPENED)
                q.emplace(r, c);
            else if (box[r][c] == TOMATO)
                ++tomatoCount;
        }
    }

    if (tomatoCount == 0)
    {
        cout << 0;
        return 0;
    }

    // 3. 토마토를 숙성시켜야 함
    int minimalDay = 0;
    while (false == q.empty())
    {
        const int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            const int dr[] = { -1, 1, 0, 0 };
            const int dc[] = { 0, 0, -1, 1 };

            for (int i = 0; i < 4; ++i)
            {
                const int nr = r + dr[i];
                const int nc = c + dc[i];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                if (box[nr][nc] == TOMATO)
                {
                    q.emplace(nr, nc);
                    box[nr][nc] = RIPENED;
                    --tomatoCount;
                }
            }
        }

        ++minimalDay;
    }

    // 4. 숙성일 수 출력
    if (tomatoCount > 0)
        cout << -1;
    else
        cout << minimalDay - 1;
}
#endif