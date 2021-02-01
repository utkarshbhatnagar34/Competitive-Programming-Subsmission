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
	while (t--) {
		string s;
		cin >> s;
		int x = 0;
		int l = s.length();
		for (int i = 0; i < l; i++)
		{
			if (s[i] == '1')
				x++;
		}

		if (l % 2 == 0 && x != l && x != 0) {
			if (x == (l / 2))
				cout << 0;
			else
			{
				cout << abs(x - (l / 2));
			}
		}
		else
			cout << -1;
		cout << endl;
	}
	return 0;
}