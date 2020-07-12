#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main(void) {
	string str;
	string temp;
	int result = 0;
	bool minus_flag = false;
	cin >> str;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			int num = stoi(temp);

			if (!minus_flag)
				result += num;
			if (minus_flag)
				result -= num;
			if (str[i] == '-') {
				minus_flag = true;
			}

			temp.clear();
		}
		else
			temp += str[i];

	}
	cout << result << endl;
	return 0;
}


