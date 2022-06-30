#ifdef SOLUTION_01_1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
vector<int> graph[1001];

void dfs(int vertex)
{
    static bool isVisited[1001] = { false };

    isVisited[vertex] = true;

    cout << vertex << ' ';

    for (int next : graph[vertex])
    {
        if (isVisited[next] == false)
            dfs(next);
    }
}

void bfs()
{
    bool isVisited[1001] = { false };

    queue<int> que;
    que.push(V);
    isVisited[V] = true;

    while (false == que.empty())
    {
        int vertex = que.front();
        que.pop();

        cout << vertex << ' ';

        for (int next : graph[vertex])
        {
            if (isVisited[next] == false)
            {
                que.push(next);
                isVisited[next] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> V;
    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 1; i <= N; ++i)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);

    cout << "\n";

    bfs();
}
#endif