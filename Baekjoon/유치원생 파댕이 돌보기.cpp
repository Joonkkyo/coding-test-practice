#include <iostream>
#include <vector>
#define rint register int
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int T, N;
	cin >> T >> N;
	int F, sum = 0;
	for (rint i = 0; i < N; ++i) {
		cin >> F;
		sum += F;
	}
	
	string ans = (sum < T) ? "Padaeng_i Cry" : "Padaeng_i Happy";
	cout << ans << endl;
	return 0;
}
