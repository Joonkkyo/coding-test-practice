#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int N;
	int cycle = 0;
	int tmp1, tmp2; //ù°, ��° �ڸ� ���� ������ ����
	int newNum = 0;
	int sum;

	scanf("%d", &N);

	newNum = N;

	do
	{
		tmp1 = newNum / 10;
		tmp2 = newNum - tmp1 * 10;
		sum = tmp1 + tmp2;
		newNum = (sum % 10) + tmp2 * 10;
		cycle++;

	} while (N != newNum);

	printf("%d\n", cycle);

	return 0;
}