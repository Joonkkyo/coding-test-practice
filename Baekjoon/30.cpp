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
		sum += s[i] - '0'; //int������ ����
	}
	if (sum % 3 == 0) {  //3�� ��� �Ǵ�
		sort(s.begin(), s.end(), greater<char>()); //��������
												   //10�� ��� �Ǵ�
		if (s.back() == '0') {
			ret = s;
		}
		//�ִ밪 => �������� ���� => 0�� �� ������
	}
	cout << ret << endl;
	return 0;
}


