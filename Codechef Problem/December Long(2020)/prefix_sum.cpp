#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int mid = n % 2 == 0 ? (n / 2) - 1 : n / 2;
		int no_neg = n - k;
		if (n == 1)
		{
			if (k == 1)
				cout << 1;
			else
				cout << -1;
		}
		else if (n == 2)
		{
			for (int i = 1; i <= n; i++)
			{
				if (no_neg > 0) {
					cout << -i << " ";
					no_neg--;
				}
				else
					cout << i << " ";
			}
		}
		else if ((no_neg) <= mid)
		{
			for (int i = 1; i <= n; i++)
			{
				if (i != 1 && i % 2 != 0 && no_neg > 0)
				{
					cout << (i * -1) << " ";
					no_neg--;
				}
				else
				{
					cout << i << " ";
				}
			}
		}
		else
		{
			//here all odd position are initially -ve
			int ev_neg = (no_neg) - mid; //no of even postion i have to make -ve
			int ev_pos = n - mid;

			int leave = ev_pos - ev_neg;
			for (int i = 1; i <= n; i++)
			{
				if (i != 1 && i % 2 != 0)
					cout << -i << " ";
				else
				{
					if (leave > 0) {
						cout << i << " ";
						leave--;
					}
					else
						cout << (i * -1) << " ";
				}
			}
		}
		cout << endl;
	}
}