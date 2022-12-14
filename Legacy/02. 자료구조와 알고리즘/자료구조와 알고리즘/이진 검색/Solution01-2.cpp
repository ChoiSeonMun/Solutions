#ifdef SOLUTION_01_2
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
// ������ ����ִ� ���� �����ε��� ��ȯ
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

// ������ ����ִ� ������ �ε��� �����ε��� ��ȯ
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
	int N = 0;			  //�־��� ī���� ����
	scanf("%d", &N);

	int arr[500'001] = {}; //�ִ� ��������� �մ� ī���� ����

	for (int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		arr[i] = x;			//�־����� ī�� �� ����
	}

	sort(arr, arr + N);		 //�����˻��� ���� ����

	int M = 0;

	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int s = 0;
		scanf("%d", &s);
		// ������ ����ִ� ���� ���� �ε���(low)�� ,������ ����ִ� ������ �ε��� ���� �ε���(high)�� ���ؼ� 
		int low = lowIndex(arr, 0, N, s);
		int high = highIndex(arr, 0, N, s);
		// high�� �ش� �迭�� ���̸� �� �����ε����� ��ȯ�ؾ��ϴ� +1 ���ش�  
		/*if (high == N - 1 && arr[N - 1] == s)
			high++;*/
			// high- low �� ���� ������ ���ش�.
		printf("%d ", high - low);
	}
	//	ex)	value 3 �ϰ�� 
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