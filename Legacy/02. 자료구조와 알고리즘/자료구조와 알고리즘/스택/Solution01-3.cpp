#ifdef SOLUTION_01_3
#include <stdio.h>

int T;

char stack[51];
int top = -1;

int main()
{
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		char str[51] = { 0 };
		scanf("%s", str);

		bool isValid = true;

		for (const char* ch = str; *ch != '\0'; ++ch)
		{
			if (*ch == '(')
				stack[++top] = *ch;
			else
			{
				if (top == -1)
				{
					isValid = false;

					break;
				}

				--top;
			}
		}

		if (isValid && top == -1)
			puts("YES");
		else
			puts("NO");

		top = -1;
	}
}
#endif