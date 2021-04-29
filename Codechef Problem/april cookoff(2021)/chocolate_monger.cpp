#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	FIO;
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		ll sum = 0;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		auto it = m.begin();
		vector<int> v(m.size());
		//storing the value of types of canndies in array and sort in desending order
		for (int i = 0; i < v.size(); i++) {
			v[i] = it->second;
			it++;
		}
		sort(v.begin(), v.end(), greater<int>());

		if (x == n)
			cout << 0;
		else {
			int type = v.size(); int i = 0, j = 0;

			while (x > 0) {
				if (j == v.size())
					j = 0;

				//break condition for infinite loop
				if (i > (2 * type))
					break;

				if (i <= type) {
					if (x >= v[j]) {
						x -= v[j] - 1;
						v[j] = 1;
					}
					else {
						v[j] -= x;
						x = 0;
						break;
					}
				}
				else {
					if (v[j] > 0) {
						x -= v[j];
						v[j] = 0;
					}
				}
				i++; j++;
			}
			int ans = 0;
			for (auto i : v) {
				if (i > 0)
					ans++;
			}
			cout << ans;
		}
		cout << endl;
	}
	return 0;
}