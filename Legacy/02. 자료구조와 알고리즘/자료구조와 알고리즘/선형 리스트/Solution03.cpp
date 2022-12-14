#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    static const int sol[3][10] = {
        { 1, 2, 3, 4, 5 },
        { 2, 1, 2, 3, 2, 4, 2, 5 },
        { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }
    };
    static const int len[] = { 5, 8, 10 };

    int counts[] = { 0, 0, 0 };
    int p[] = { 0, 0, 0 };

    for (int ans : answers)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (sol[i][p[i]] == ans)
                ++counts[i];

            p[i] = (p[i] + 1) % len[i];
        }
    }

    int highestCount = counts[0];

    for (int i = 1; i < 3; ++i)
    {
        if (highestCount < counts[i])
            highestCount = counts[i];
    }

    vector<int> answer;

    for (int i = 0; i < 3; ++i)
    {
        if (highestCount == counts[i])
            answer.push_back(i + 1);
    }

    return answer;
}