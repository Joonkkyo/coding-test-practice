#include <iostream>
#include <vector>
#define rint register int
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	string N;
	int B, parsedValue, sum = 0;
	cin >> N >> B;
	int pos = N.size();
	for (rint i = 0; i < N.size(); ++i) {
		if ('0' <= N[i] && N[i] <= '9') {
			parsedValue = N[i] - '0';
			sum += parsedValue * pow(B, --pos);
		} else {
			parsedValue = N[i] - 'A' + 10;
			sum += parsedValue * pow(B, --pos);
		}
	}

	cout << sum << '\n';
	return 0;
}
