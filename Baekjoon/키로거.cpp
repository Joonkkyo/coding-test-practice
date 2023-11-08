#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	string str;

	cin >> tc;
	while (tc--)
	{
		list<char> l;
		list<char>::iterator it = l.begin();
		
		cin >> str;

		for (char c : str)
		{
			if (c == '<')
			{
				if (it != l.begin()) it--;
			}

			else if (c == '>')
			{
				if (it != l.end()) it++;
			}

			else if (c == '-')
			{
				if (it != l.begin()) l.erase(prev(it));
			}

			else l.insert(it, c);
		}

		for (char str : l)
			cout << str;
		cout << '\n';
	}

	return 0;
}
