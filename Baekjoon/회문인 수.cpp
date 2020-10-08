#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

bool palin(int n, int mal) {
    stack<int> s;
    while (n) {
        s.push(n % mal);
        n /= mal;
    }

    vector<int> ten;
    while (!s.empty()) {
        ten.push_back(s.top());
        s.pop();
    }

    int idx = 0;
    while (idx < ten.size() / 2) {
        if (ten[idx] != ten[ten.size() - idx - 1])
            return false;
        idx++;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int flag = 0;
        for (int mal = 2; mal <= 64; mal++) {
            if (palin(n, mal))
                flag = 1;
        }
        if (flag)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}