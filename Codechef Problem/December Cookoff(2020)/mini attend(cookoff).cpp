#include <bits/stdc++.h>
#include <string>
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
		int n;
		cin >> n;
		char ch[n];
		int x = 0, y = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> ch[i];
			if (ch[i] == '1')
				x++;
		}
		//cout << x << endl;
		if (n < 120) {
			y = 120 - n;
			if ((x + y) >= 90)
				cout << "YES";
			else
				cout << "NO";
		}
		else {
			if (x >= 90)
				cout << "YES";
			else
				cout << "NO";
		}
		cout << endl;
	}
}