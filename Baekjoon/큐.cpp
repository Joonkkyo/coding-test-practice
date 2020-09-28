#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int queue[10001];
int main(void)
{
	ios::sync_with_stdio(false);
	int testCase;
	int currentElementCount = 0;
	int data;
	int front = 0;
	int rear = 0;
	string op;
	cin >> testCase;

	while (testCase--)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> data;
			queue[rear++] = data;
			currentElementCount++;
		}

		else if (op == "pop")
		{
			if (currentElementCount == 0)
				cout << -1 << endl;
			else
			{
				cout << queue[front++] << endl;
				currentElementCount--;
			}
		}

		else if (op == "size")
			cout << currentElementCount << endl;

		else if (op == "empty")
		{
			if (currentElementCount > 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}

		else if (op == "front")
		{
			if (currentElementCount == 0)
				cout << -1 << endl;
			else
				cout << queue[front] << endl;
		}

		else if (op == "back")
		{
			if (currentElementCount == 0)
				cout << -1 << endl;
			else
				cout << queue[rear - 1] << endl;
		}
	}
	return 0;
}
