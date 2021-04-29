#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
/*
eg:-
x=1 3 -5 6
y=1 2 3 4

2 13 34 52=1+3+5+7=18

37 29 18 17=6+5+4+4=19*/

//binary exponenciation
ll power(ll a, ll b) {
	ll result = 1;
	while (b > 0) {
		if (b % 2 == 1)
			result = (result * 1LL * a);
		a = (a * 1ll * a);
		b = b / 2;
	}
	return result;
}
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
		int n;
		cin >> n;
		ll x[n];
		ll y[n];
		ll a, b; int i = 0, j = 0;
		for (int k = 0; k < 2 * n; k++) {
			cin >> a >> b;
			if (b == 0) {
				x[i] = abs(a);
				i++;
			}
			else {
				y[j] = abs(b);
				j++;
			}
		}
		sort(x, x + n);
		sort(y, y + n);
		double ans = 0;
		ll sum = 0;
		for (int k = 0; k < n; k++) {
			sum = power(x[k], 2) + power(y[k], 2);
			//cout << sum << endll;
			ans = ans + sqrt(sum);
		}
		cout.precision(15);
		cout << std::fixed << ans << endll;
	}
	return 0;
}