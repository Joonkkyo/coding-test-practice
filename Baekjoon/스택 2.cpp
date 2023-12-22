#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define rint register int
#define pii pair<int, int>
using namespace std;

constexpr int MAX_N = 1000001;

template<typename T>
struct stack {
	int pos;
	T data[MAX_N];
	void clear() { pos = 0; }
	T pop() { return (pos != 0) ? data[pos--] : -1; }
	int size() { return pos; }
	void push(T val) { data[++pos] = val; }
	int empty() { return (pos == 0) ? 1 : 0; }
	T top() { return (pos != 0) ? data[pos] : -1; }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int N, op, num;
	stack<int> st;
	cin >> N;

	st.clear();
	while (N--) {
		cin >> op;
		switch (op) {
		case 1:
			cin >> num;
			st.push(num);
			break;
		case 2:
			cout << st.pop() << '\n';
			break;
		case 3:
			cout << st.size() << '\n';
			break;
		case 4:
			cout << st.empty() << '\n';
			break;
		case 5:
			cout << st.top() << '\n';
			break;
		}
	}

	return 0;
}
