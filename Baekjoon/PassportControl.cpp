#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ifstream inStream;
	inStream.open("input.txt");
	int testCase;
	int N, k, num;  // N : �Ա� �°� ��, k : ���� �ɻ� û�� ��
	inStream >> testCase;
	while (testCase--)
	{
		inStream >> N >> k;
		if (inStream.peek() == EOF)
			break;

		int wait[101] = { 0 };
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			inStream >> num;
			int m = 1;

			while (m <= k && cnt != -1)
			{
				if (wait[m] < num)
				{
					wait[m] = num;
					break;
				}
				else
					m++;
			}
			if (m > k) cnt = -1;
		}

		if (cnt == -1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}