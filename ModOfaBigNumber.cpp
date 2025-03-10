#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
	string s;
	cin >> s;
	int m;
	cin >> m;
	ll ans = 0;

	for (int i = 0; i < s.size(); i++) {
		ans = (ans * 10 + (s[i] - '0')) % m;
	}
	cout << ans << endl;

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
