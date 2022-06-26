#ifdef SOLUTION_01_2
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
// 벨류가 들어있는 가장 작은인덱스 반환
int lowIndex(const int* arr, int s, int e, int value)
{
	while (e > s)
	{
		int m = (s + e) / 2;
		if (arr[m] >= value)
			e = m;
		else
			s = m + 1;
	}
	return e;
}

// 벨류가 들어있는 마지막 인덱스 다음인덱스 반환
int highIndex(const int* arr, int s, int e, int value)
{
	int max = e;
	while (e > s)
	{
		int m = (s + e) / 2;
		if (arr[m] > value)
			e = m;
		else
			s = m + 1;
	}

	return e;
}

int main()
{
	int N = 0;			  //주어질 카드의 개수
	scanf("%d", &N);

	int arr[500'001] = {}; //최대 들고있을수 잇는 카드의 개수

	for (int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		arr[i] = x;			//주어지는 카드 값 삽입
	}

	sort(arr, arr + N);		 //이진검색을 위한 정렬

	int M = 0;

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int s = 0;
		scanf("%d", &s);
		// 벨류가 들어있는 가장 적은 인덱스(low)와 ,벨류가 들어있는 마지막 인덱스 다음 인덱스(high)를 구해서 
		int low = lowIndex(arr, 0, N, s);
		int high = highIndex(arr, 0, N, s);
		// high가 해당 배열에 끝이면 그 다음인덱스를 반환해야하니 +1 해준다  
		/*if (high == N - 1 && arr[N - 1] == s)
			high++;*/
			// high- low 를 통해 갯수를 세준다.
		printf("%d ", high - low);
	}
	//	ex)	value 3 일경우 
	//	[-10] [-10] [2] [3] [3] [6] [7] [10] [10] [10]
	//				   low(3)  high(5)
	//  5-3 = 2 
}
#elif SOLUTION_01_2_STL
#include <stdio.h>
#include <algorithm>

int N, M;
int arr[500'000];

using namespace std;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int n;
		scanf("%d", &n);

		auto eq = equal_range(arr, arr + N, n);

		printf("%d ", eq.second - eq.first);
	}
}
#endif