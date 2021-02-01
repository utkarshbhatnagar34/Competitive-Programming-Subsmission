#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int x, y, k, n;
		cin >> x >> y >> k >> n;
		if (abs(x - y) % (2 * k) == 0)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}