#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define rint register int
#define ll long long
using namespace std;

struct Point {
	ll x;
	ll y;
};

vector<Point> v;
stack<Point> st;

int CCW(const Point& a, const Point& b, const Point& c)
{
	ll result = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
	if (result > 0) return 1; // 반시계
	else if (result < 0) return -1; // 시계
	else return 0; // 일직선
}

bool val_cmp(const Point& a, const Point& b)
{
	if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

bool angle_cmp(const Point& a, const Point& b)
{
	ll dir = CCW(v[0], a, b);
	if (dir) return dir == 1;
	else return val_cmp(a, b);
}

void init()
{
	v.clear();
	st = stack<Point>();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;
	for (rint tc = 1; tc <= T; ++tc)
	{
		init();
		cin >> N;
		ll x, y;
		for (rint i = 0; i < N; ++i)
		{
			cin >> x >> y;
			v.push_back({ x, y });
		}

		sort(v.begin(), v.end(), val_cmp);
		sort(v.begin() + 1, v.end(), angle_cmp);

		Point p1, p2, p3;
		p1 = v[0], p2 = v[1];
		st.push(p1);
		st.push(p2);

		for (rint i = 2; i < N; ++i)
		{
			p3 = v[i];
			while (st.size() > 1)
			{
				p2 = st.top();
				st.pop();
				p1 = st.top();

				if (CCW(p1, p2, p3) == 1)
				{
					st.push(p2);
					break;
				}
			}

			st.push(p3);
		}

		cout << "#" << tc << " " << st.size() << endl;
	}

	return 0;
}
