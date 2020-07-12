#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

long int box[MAX][MAX];
int check[MAX][MAX] = { 0, };

int main(void) {
	std::ios::sync_with_stdio(false);
	int T;
	int n, m;
	vector<long int> sideMax;
	vector<long int> frontMax;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		long int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[i][j];
			}
		}

		for (int i = 0; i < n; i++) {  //side(Çà) ÃÖ´ñ°ª ÀúÀå
			int temp = 0;
			for (int j = 0; j < m; j++) {
				if (temp < box[i][j])
					temp = box[i][j];
				if (j == m - 1)
					sideMax.push_back(temp);
			}
		}

		for (int i = 0; i < m; i++) {  //front(¿­) ÃÖ´ñ°ª ÀúÀå
			int temp = 0;
			for (int j = 0; j < n; j++) {
				if (temp < box[j][i])
					temp = box[j][i];
				if (j == n - 1)
					frontMax.push_back(temp);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (sideMax[i] == box[i][j])
					check[i][j] = 1;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (frontMax[i] == box[j][i])
					check[j][i] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] == 0)
					sum += box[i][j];
			}
		}
		cout << sum << endl;
		frontMax.clear();
		sideMax.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				check[i][j] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				box[i][j] = 0;
		}
	}
	return 0;
}

