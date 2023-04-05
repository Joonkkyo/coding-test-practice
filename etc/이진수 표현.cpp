#include <iostream>
#include <vector>
using namespace std;

string checkBitState(const vector<int>& v, int n)
{
	int len = v.size();
	if (len < n)
		return "OFF";
	
	for (int i = 0; i < n; i++)
	{
		if (v[i] == 0)
			return "OFF";
	}

	return "ON";
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> bin;
		int N, M;
		cin >> N >> M;
		
		while (M != 0)
		{
			if (M % 2 == 0)
				bin.push_back(0);
			else
				bin.push_back(1);
			M /= 2;
		}

		cout << '#' << test_case << " " << checkBitState(bin, N) << endl;
	}

	return 0;
}
