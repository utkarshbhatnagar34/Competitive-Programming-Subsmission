#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());


inline int operation(int x, int p)
{
	int k;
	k = x ^ p;
	return k;
}
inline int operation1(int x, int p)
{
	if (x == 0 && p == 0)
		return 1;
	int k, i;
	int led_zr = __builtin_clz(p);
	i = 32 - led_zr;
	k = x ^ (1 << (i - 1));
	return k;
}
inline int operation2(int x, int p)
{
	if (x == 0 && p == 0)
		return 1;

	int msb = p & (~(p - 1));
	cout << msb << endl;

	x = x ^ msb;
	return x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int a[n];
		int p;
		int copy[n];
		int k1 = 0; //xor of all
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			copy[i] = a[i];
			k1 = k1 ^ a[i];
		}
		//find mn and mx
		//finding mn
		int mn = 0;
		int k2 = k1 ^ a[n - 1];
		mn +=  __builtin_popcount(k2);
		int orr = 0;
		int h;
		int b;
		for (int i = 0; i < n - 1; i++) {
			h = k2 & (a[i]);
			b = abs(a[i] - h);
			k2 = abs(k2 - h);
			orr = orr | (b);
		}
		mn += __builtin_popcount(orr);//mininum number of steps
		if (mn < n / 2)
			mn = n / 2;
		//found  mn
		//doing main operation

		if (x < mn || n == 2)
		{
			int j = 0;
			int led_zr;
			int cc = 0;
			int ij, ik;
			while (x)
			{
				while (a[j] == 0)
					j++;

				if (j >= n - 1)
					break;

				cc = 0;
				p = a[j];
				a[j] = operation1(a[j], p);
				led_zr = __builtin_clz(p);//p=0->31 p=1->31
				ij = 32 - led_zr;
				ik = (1 << (ij - 1));
				for (int i = j + 1; i < n - 1; i++)
				{
					if ((a[i]&ik) > 0)
					{
						cc++;
						a[i] = a[i] ^ p;
						break;
					}
				}
				if (cc == 0)
				{
					a[n - 1] = operation1(a[n - 1], p);
				}

				x--;
			}
			if (x > 0)
			{
				if (k1 == 0) {
					//use even odd concept here
					//even remain same odd changes
					if (x % 2 != 0)
					{
						p = a[n - 1];
						a[n - 1] = operation2(a[n - 1], p);
						a[n - 2] = operation2(a[n - 2], p);
					}
				}
				else
				{
					//use even odd concept here
					if (x % 2 != 0)
					{
						p = 1;
						a[n - 1] = operation1(a[n - 1], p);
						a[n - 2] = operation1(a[n - 2], p);
					}
				}
			}
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (i == n - 1)
					cout << k1;
				else
					cout << 0 << " ";
			}
		}

		cout << endl;

	}
}