#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Point {
	int x;
	int y;
};

bool onSegment(Point p, Point q, Point r) {
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
	        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

int orientation(Point p, Point q, Point r) {
	int val = (q.y - p.y) * (r.x - q.x) -
	          (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;

	return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {

	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);


	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false;
}



void solve() {

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	struct Point p1 = {x1, y1}, q1 = {x2, y2};
	struct Point p2 = {a, b}, q2 = {c, d};

	if (doIntersect(p1, q1, p2, q2)) {
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;

}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc = 1;
	//cin >> tc;
	for (int i = 1; i <= tc; i++) {
		solve();
	}
}
