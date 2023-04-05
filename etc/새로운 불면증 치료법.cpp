#include <iostream>
#include <set>
using namespace std;

bool isValidSet(set<int> s)
{
	return (s.size() == 10) ? false : true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		set<int> num_set;
		int N, count = 0, idx = 1;
		cin >> N;
		int temp = N;
    
		while (isValidSet(num_set))
		{
			N = temp * idx++;
			while (N != 0)
			{
				num_set.insert(N % 10);
				N /= 10;
			}
			count++;
		}
		cout << '#' << test_case << " " << temp * count << endl;
	}
	return 0;
}
