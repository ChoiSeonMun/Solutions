#ifdef SOLUTION_01_1
#include <stdio.h>
#include <string.h>

#define IS_EQUAL(lhs, rhs) (0 == strcmp(lhs, rhs))

int N;

class Stack
{
public:
	void		Push(int x) { stack[++top] = x; }
	int			Pop() { if (Empty()) return -1; return stack[top--]; }
	int			Size() { return top + 1; }
	int			Empty() { return top == -1; }
	int			Top() { if (Empty()) return -1; return stack[top]; }
private:
	int			stack[10000] = { 0 };
	int			top = -1; // int size = 0;
} st;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		char op[16] = { 0 };
		scanf("%s", op);

		if (IS_EQUAL(op, "push"))
		{
			int x = 0;
			scanf("%d", &x);

			st.Push(x);
		}
		else if (IS_EQUAL(op, "pop"))
			printf("%d\n", st.Pop());
		else if (IS_EQUAL(op, "size"))
			printf("%d\n", st.Size());
		else if (IS_EQUAL(op, "empty"))
			printf("%d\n", st.Empty());
		else if (IS_EQUAL(op, "top"))
			printf("%d\n", st.Top());
	}
}
#endif