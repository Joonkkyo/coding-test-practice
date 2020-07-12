#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int len = s.size();
	int sum = 0;
	string ret = "-1";
	for (int i = 0; i < len; i++) {
		sum += s[i] - '0'; //int형으로 변경
	}
	if (sum % 3 == 0) {  //3의 배수 판단
		sort(s.begin(), s.end(), greater<char>()); //내림차순
												   //10의 배수 판단
		if (s.back() == '0') {
			ret = s;
		}
		//최대값 => 내림차순 정렬 => 0이 맨 마지막
	}
	cout << ret << endl;
	return 0;
}


