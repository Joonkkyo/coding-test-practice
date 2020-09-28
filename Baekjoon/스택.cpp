#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int stack[10001];

int main(void)
{
	int n, num;
	int idx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char cmd[BUFSIZ];
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0)
		{
			scanf("%d", &num);
			stack[idx] = num;
			idx++;
		}
		if (strcmp(cmd, "pop") == 0)
		{
			if (idx <= 0)
				printf("-1\n");

			else
			{
				printf("%d\n", stack[idx - 1]);
				idx--;
			}
		}
		if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", idx);
		}
		if (strcmp(cmd, "empty") == 0)
		{
			if (idx <= 0)
				printf("1\n");
			else
				printf("0\n");
		}
		if (strcmp(cmd, "top") == 0)
		{
			if (idx <= 0)
				printf("-1\n");

			else
				printf("%d\n", stack[idx - 1]);
		}
	}
	return 0;
}