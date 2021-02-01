#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		ll a[n], b[m];
		ll s1 = 0, s2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s1 += a[i];
		}
		for (int j = 0; j < m; j++) {
			cin >> b[j];
			s2 += b[j];
		}
		if (s1 > s2)
			cout << 0 << endll;
		else if (s1 == s2) {
			sort(a, a + n);
			sort(b, b + m);
			//binary search the array b such that any number in b[] is greater than the mininim numbr of a[]
			if (a[0] < b[m - 1])
				cout << 1 << endll;
			else
				cout << -1 << endll;
		}
		else { //s1<s2
			ll r_dif = 0;
			bool c = false, flag = false;
			sort(a, a + n);
			sort(b, b + m, greater<ll>());
			int x = 0, y = 0;
			int move = 0;
			while (a[x] < b[y] && x < n && y < m) {
				c = true;
				r_dif += b[y] - a[x];
				//cout << r_dif << endll;
				move++;
				//condition
				if ((s1 + r_dif) > (s2 - r_dif)) {
					flag = true;
					break;
				}
				x++;
				y++;
			}
			if (c) {
				if (flag)
					cout << move << endll;
				else
					cout << -1 << endll;
			}
			else
				cout << -1 << endll;
		}

	}
	return 0;
}