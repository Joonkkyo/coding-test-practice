#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int board[5][5];
	int OX[5][5] = { 0, };
	int bingoCnt = 0;
	int seroCheck[5] = { 0, };
	int garoCheck[5] = { 0, };
	int diagCheck1 = 0;
	int diagCheck2 = 0;
	int callNum;
	int index = 0;
	int sum;
	int checkIdx;
	int retVal;
	int breakCnt1 = 0;
	int breakCnt2 = 0;

	for (int i = 0; i < 5; i++) {  //빙고판 숫자 입력
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 25; i++) {  //pair을 이용하면 시간복잡도를 줄일 수 있다.
		cin >> callNum;
		index++;

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (callNum == board[j][k]) {
					OX[j][k] = 1;
					break;
				}
			}
		}

		for (int m = 0; m < 5; m++) {  //가로 빙고 검사
			sum = 0;
			checkIdx = 0;
			for (int n = 0; n < 5; n++) {
				sum += OX[m][n];
				checkIdx = m;
			}

			if (garoCheck[checkIdx] == 0) {
				if (sum == 5) {
					bingoCnt++;
					garoCheck[checkIdx] = 1;
				}

				if (bingoCnt == 3) {
					retVal = index;
					breakCnt2++;
					break;
				}
			}
		}

		//if (breakCnt2 == 1)
		//	break;

		for (int m = 0; m < 5; m++) {  //세로 빙고 검사
			sum = 0;
			checkIdx = 0;
			for (int n = 0; n < 5; n++) {
				sum += OX[n][m];
				checkIdx = m;
			}

			if (seroCheck[checkIdx] == 0) {
				if (sum == 5) {
					bingoCnt++;
					seroCheck[checkIdx] = 1;
				}

				if (bingoCnt == 3) {
					retVal = index;
					breakCnt2++;
					break;
				}
			}
		}

		//if (breakCnt2 == 1)
		//	break;

		sum = 0;

		for (int m = 0; m < 5; m++) { //좌상단 대각선 검사
			sum += OX[m][m];
		}

		if (diagCheck1 == 0) {

			if (sum == 5) {
				bingoCnt++;
				diagCheck1 = 1;
			}

			if (bingoCnt == 3) {
				retVal = index;
				break;
			}
		}

		sum = 0;

		for (int m = 0; m < 5; m++) { //우상단 대각선 검사
			sum += OX[m][4 - m];
		}
		if (diagCheck2 == 0) {
			if (sum == 5) {
				bingoCnt++;
				diagCheck2 = 1;
			}

			if (bingoCnt == 3) {
				retVal = index;
				break;
			}
		}
		/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		cout << OX[i][j];
		cout << "" << endl;
		}
		cout << "" << endl;*/
	}
	cout << retVal << endl;
	//cout << bingoCnt << endl;
	return 0;
}