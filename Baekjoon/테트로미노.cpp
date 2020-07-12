#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#define MAX 500
using namespace std;

int main(void) {
	int width, height;
	int b1_max, b2_max, b3_max;
	int result;
	vector<int> total_max;
	vector<int> block1_max;
	vector<int> block2_max;
	vector<int> block3_max;
	int sum1, sum2, sum3, sum4, sum5, sum6, sum7,
		sum8, sum9, sum10, sum11, sum12, sum13, sum14,
		sum15, sum16, sum17, sum18, sum19;
	int max1 = 0, max2 = 0, max3 = 0, max4 = 0, max5 = 0, max6 = 0,
		max7 = 0, max8 = 0, max9 = 0, max10 = 0, max11 = 0, max12 = 0,
		max13 = 0, max14 = 0, max15 = 0, max16 = 0, max17 = 0, max18 = 0,
		max19 = 0;
	int board[MAX][MAX];
	ios::sync_with_stdio(false);

	cin >> height >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < height; i++) {  //직선 모양 테트로미노의 합의 최댓값(가로)
		for (int m = 0; m < width - 3; m++) {
			sum1 = 0;
			for (int j = m; j < 4 + m; j++)
				sum1 += board[i][j];
			if (max1 < sum1)
				max1 = sum1;
		}
	}

	for (int i = 0; i < width; i++) {  //직선 모양 테트로미노의 합의 최댓값(세로)
		for (int m = 0; m < height - 3; m++) {
			sum2 = 0;
			for (int j = m; j < 4 + m; j++)
				sum2 += board[j][i];
			if (max2 < sum2)
				max2 = sum2;
		}
	}

	if (max1 > max2)
		total_max.push_back(max1);
	else
		total_max.push_back(max2);

	for (int i = 0; i < height - 1; i++) {  //정사각형 모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum3 = 0;

			sum3 += board[i][j];
			sum3 += board[i][j + 1];
			sum3 += board[i + 1][j];
			sum3 += board[i + 1][j + 1];

			if (max3 < sum3)
				max3 = sum3;
		}
	}
	total_max.push_back(max3);

	for (int i = 0; i < height - 2; i++) {   //ㄴ(세로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum4 = 0;

			sum4 += board[i][j];
			sum4 += board[i + 1][j];
			sum4 += board[i + 2][j];
			sum4 += board[i + 2][j + 1];

			if (max4 < sum4)
				max4 = sum4;
		}
	}
	block1_max.push_back(max4);

	for (int i = 0; i < height - 2; i++) {   //┘(세로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum5 = 0;

			sum5 += board[i][j + 1];
			sum5 += board[i + 1][j + 1];
			sum5 += board[i + 2][j + 1];
			sum5 += board[i + 2][j];

			if (max5 < sum5)
				max5 = sum5;
		}
	}

	block1_max.push_back(max5);

	for (int i = 0; i < height - 1; i++) {   //┌(가로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum6 = 0;

			sum6 += board[i][j];
			sum6 += board[i][j + 1];
			sum6 += board[i][j + 2];
			sum6 += board[i + 1][j];

			if (max6 < sum6)
				max6 = sum6;
		}
	}

	block1_max.push_back(max6);

	for (int i = 0; i < height - 1; i++) {   //┐(가로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum7 = 0;

			sum7 += board[i][j];
			sum7 += board[i][j + 1];
			sum7 += board[i][j + 2];
			sum7 += board[i + 1][j + 2];

			if (max7 < sum7)
				max7 = sum7;
		}
	}

	block1_max.push_back(max7);

	for (int i = 0; i < height - 2; i++) {   //┌(세로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum8 = 0;

			sum8 += board[i][j];
			sum8 += board[i][j + 1];
			sum8 += board[i + 1][j];
			sum8 += board[i + 2][j];

			if (max8 < sum8)
				max8 = sum8;
		}
	}

	block1_max.push_back(max8);

	for (int i = 0; i < height - 2; i++) {   //┐(세로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum9 = 0;

			sum9 += board[i][j];
			sum9 += board[i][j + 1];
			sum9 += board[i + 1][j + 1];
			sum9 += board[i + 2][j + 1];

			if (max9 < sum9)
				max9 = sum9;
		}
	}

	block1_max.push_back(max9);

	for (int i = 0; i < height - 1; i++) {   //ㄴ(가로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum10 = 0;

			sum10 += board[i][j];
			sum10 += board[i + 1][j];
			sum10 += board[i + 1][j + 1];
			sum10 += board[i + 1][j + 2];

			if (max10 < sum10)
				max10 = sum10;
		}
	}

	block1_max.push_back(max10);

	for (int i = 0; i < height - 1; i++) {   //┘(가로가 긴)모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum11 = 0;

			sum11 += board[i + 1][j];
			sum11 += board[i + 1][j + 1];
			sum11 += board[i + 1][j + 2];
			sum11 += board[i][j + 2];

			if (max11 < sum11)
				max11 = sum11;
		}
	}

	block1_max.push_back(max11);
	sort(block1_max.begin(), block1_max.end());
	b1_max = block1_max.back();
	total_max.push_back(b1_max);

	for (int i = 0; i < height - 2; i++) {   //두 번째 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum12 = 0;

			sum12 += board[i][j];
			sum12 += board[i + 1][j];
			sum12 += board[i + 1][j + 1];
			sum12 += board[i + 2][j + 1];

			if (max12 < sum12)
				max12 = sum12;
		}
	}
	block2_max.push_back(max12);

	for (int i = 0; i < height - 2; i++) {   //두 번째 테트로미노(대칭)의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum13 = 0;

			sum13 += board[i][j + 1];
			sum13 += board[i + 1][j + 1];
			sum13 += board[i + 1][j];
			sum13 += board[i + 2][j];

			if (max13 < sum13)
				max13 = sum13;
		}
	}

	block2_max.push_back(max13);

	for (int i = 0; i < height - 1; i++) {   //두 번째 테트로미노(회전)의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum14 = 0;

			sum14 += board[i][j + 1];
			sum14 += board[i][j + 2];
			sum14 += board[i + 1][j];
			sum14 += board[i + 1][j + 1];

			if (max14 < sum14)
				max14 = sum14;
		}
	}
	block2_max.push_back(max14);

	for (int i = 0; i < height - 1; i++) {   //두 번째 테트로미노(회전)의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum15 = 0;

			sum15 += board[i][j];
			sum15 += board[i][j + 1];
			sum15 += board[i + 1][j + 1];
			sum15 += board[i + 1][j + 2];

			if (max15 < sum15)
				max15 = sum15;
		}
	}
	block2_max.push_back(max15);
	sort(block2_max.begin(), block2_max.end());
	b2_max = block2_max.back();
	total_max.push_back(b2_max);

	for (int i = 0; i < height - 2; i++) {   //ㅏ모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum16 = 0;

			sum16 += board[i][j];
			sum16 += board[i + 1][j];
			sum16 += board[i + 1][j + 1];
			sum16 += board[i + 2][j];

			if (max16 < sum16)
				max16 = sum16;
		}
	}
	block3_max.push_back(max16);

	for (int i = 0; i < height - 2; i++) {   //ㅓ모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 1; j++) {
			sum17 = 0;

			sum17 += board[i][j + 1];
			sum17 += board[i + 1][j + 1];
			sum17 += board[i + 1][j];
			sum17 += board[i + 2][j + 1];

			if (max17 < sum17)
				max17 = sum17;
		}
	}
	block3_max.push_back(max17);

	for (int i = 0; i < height - 1; i++) {   //ㅗ모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum18 = 0;

			sum18 += board[i][j + 1];
			sum18 += board[i + 1][j];
			sum18 += board[i + 1][j + 1];
			sum18 += board[i + 1][j + 2];

			if (max18 < sum18)
				max18 = sum18;
		}
	}
	block3_max.push_back(max18);

	for (int i = 0; i < height - 1; i++) {   //ㅜ모양 테트로미노의 합의 최댓값
		for (int j = 0; j < width - 2; j++) {
			sum19 = 0;

			sum19 += board[i][j];
			sum19 += board[i][j + 1];
			sum19 += board[i][j + 2];
			sum19 += board[i + 1][j + 1];

			if (max19 < sum19)
				max19 = sum19;
		}
	}
	block3_max.push_back(max19);
	sort(block3_max.begin(), block3_max.end());
	b3_max = block3_max.back();
	total_max.push_back(b3_max);

	sort(total_max.begin(), total_max.end());
	result = total_max.back();
	cout << result << endl;
}
