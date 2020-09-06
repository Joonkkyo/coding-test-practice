#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
	int cnt = 0;
	int minCnt = 0;
	int size = name.size();
	for (int i = 0; i < size; i++) {
		if (name[i] == 'A') {
			continue;
		}
		char tmp = 'A';
		char tmp2, tmp3;
		int tmpCnt1 = 0;
		int tmpCnt2 = 0;
		for (int j = 0; j < 26; j++) {
			tmp2 = (char)(tmp + j);
			if (tmp2 == name[i]) {
				tmpCnt1 += j;
				break;
			}
		}
		for (int k = 0; k < 26; k++) {
			tmp3 = (char)(tmp + 26 - k);
			if (tmp3 == name[i]) {
				tmpCnt2 += k;
				break;
			}
		}
		if (tmpCnt1 >= tmpCnt2)
			minCnt = tmpCnt2;
		else
			minCnt = tmpCnt1;
		cnt += minCnt;
	}

	int leftDst = 0;
	int rightDst = 0;
	int minDst;

	for (int i = 0; i < size; i++) {
		if (name[i] != 'A')
			rightDst = i;
	}

	for (int i = 1; i < size; i++) {
		if (name[size - i] != 'A')
			leftDst = i;
	}
	minDst = min(rightDst, leftDst);
	cnt += minDst;

	return cnt;
}