#ifdef SOLUTION_01_4
#include <stdio.h>
#include <string.h>

int main()
{
	while (true)
	{
		char str[128] = { 0 };
		fgets(str, 128, stdin);

		if (0 == strcmp(str, ".\n"))
			break;

		char stack[101] = { 0 };
		int top = -1;

		bool isValid = true;

		for (const char* ch = str; *ch != '\0'; ++ch)
		{
			switch (*ch)
			{
			case '(': case'[':
				stack[++top] = *ch;
				break;
			case ']':
				if (top == -1 || stack[top] != '[')
				{
					isValid = false;

					break;
				}

				--top;

				break;
			case ')':
				if (top == -1 || stack[top] != '(')
				{
					isValid = false;

					break;
				}

				--top;
			default:
				break;
			}
		}

		if (isValid && top == -1)
			puts("yes");
		else
			puts("no");
	}
}
#endif