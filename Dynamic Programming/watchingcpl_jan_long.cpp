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
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		int c = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] >= k) {
				c++;
				v[i] = 0;
			}
		}
		sort(v.begin(), v.end(), greater<int>());
		int s = 0;
		int s1 = 0;
		int box = 0;
		if (c < 2) {
			for (int i = 0; i < n; i++) {

				if (c == 2)
					break;
			}
		}
		else
			cout << 2 << endll;

	}
	return 0;
}