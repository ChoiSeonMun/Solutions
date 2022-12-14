#ifdef SOLUTION_01_7
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H;
int box[100][100][100];
enum { EMPTY = -1, TOMATO, RIPENED };

using Coord = tuple<int, int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. M, N을 입력 받는다.
    cin >> M >> N >> H;

    // 2. 토마토 상자의 정보를 입력 받는다.
    queue<Coord> q;
    int tomatoCount = 0;
    for (int h = 0; h < H; ++h)
    {
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < M; ++c)
            {
                cin >> box[h][r][c];

                if (box[h][r][c] == RIPENED)
                    q.emplace(h, r, c);
                else if (box[h][r][c] == TOMATO)
                    ++tomatoCount;
            }
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
            auto [h, r, c] = q.front();
            q.pop();

            const int dh[] = { 0, 0, 0, 0, -1, 1 };
            const int dr[] = { -1, 1, 0, 0, 0, 0 };
            const int dc[] = { 0, 0, -1, 1, 0, 0 };

            for (int i = 0; i < 6; ++i)
            {
                const int nh = h + dh[i];
                const int nr = r + dr[i];
                const int nc = c + dc[i];

                if (nh < 0 || nh >= H || nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                if (box[nh][nr][nc] == TOMATO)
                {
                    q.emplace(nh, nr, nc);
                    box[nh][nr][nc] = RIPENED;
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