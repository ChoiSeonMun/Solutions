#ifdef SOLUTION_01_1
#include <stdio.h>
#include <string.h>

class Q
{
public:
	void	Push(int v) { arr[rear] = v; rear = (rear + 1) % 2'000'000; ++size; }
	int		Pop() { if (Empty()) return -1; int r = arr[front]; front = (front + 1) % 2'000'000; --size; return r; }
	int		Size() { return size; }
	int		Empty() { return (size == 0); }
	int		Front() { return Empty() ? -1 : arr[front]; }
	int		Back() { return Empty() ? -1 : arr[rear - 1]; }
private:
	int		arr[2'000'000];
	int		front = 0;
	int		rear = 0;
	int		size = 0;
};

Q q;
int N;
char op[16];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%s", op);

		if (0 == strcmp(op, "push"))
		{
			int v = 0;
			scanf("%d", &v);

			q.Push(v);
		}
		else if (0 == strcmp(op, "pop"))
			printf("%d\n", q.Pop());
		else if (0 == strcmp(op, "size"))
			printf("%d\n", q.Size());
		else if (0 == strcmp(op, "empty"))
			printf("%d\n", q.Empty());
		else if (0 == strcmp(op, "front"))
			printf("%d\n", q.Front());
		else if (0 == strcmp(op, "back"))
			printf("%d\n", q.Back());
	}
}
#endif