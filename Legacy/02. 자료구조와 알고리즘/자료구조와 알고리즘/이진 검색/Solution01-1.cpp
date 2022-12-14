#ifdef SOLUTION_01_1_RECURSIVE
#include <stdio.h>
#include <algorithm>

int N, M;
int arr[100'000];

int bs(int s, int e, int v)
{
    if (s >= e)
        return 0;

    int m = (s + e) / 2;

    if (arr[m] == v)
        return 1;

    if (arr[m] < v)
        return bs(m + 1, e, v);
    else
        return bs(s, m, v);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + N);

    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        int n;
        scanf("%d", &n);

        printf("%d\n", bs(0, N, n));
    }
}
#elif SOLUTION_01_1_ITERATION
#include <stdio.h>
#include <algorithm>

int N, M;
int arr[100'000];

int bs(int s, int e, int v)
{
    while (s < e)
    {
        int m = (s + e) / 2;

        if (arr[m] == v)
            return 1;
        else if (arr[m] < v)
            s = m + 1;
        else
            e = m;
    }

    return 0;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + N);

    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        int n;
        scanf("%d", &n);

        printf("%d\n", bs(0, N, n));
    }
}
#elif SOLUTION_01_1_STL
#include <stdio.h>
#include <algorithm>

int arr[100'000];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    std::sort(arr, arr + N);

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        int num;
        scanf("%d", &num);

        if (std::binary_search(arr, arr + N, num))
        {
            puts("1");
        }
        else
        {
            puts("0");
        }
    }
}
#endif



