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
	int n;
	cin >> n;
	float p[n];
	float product = 1;
	float divi[n];
	float sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		product *= p[i];
		divi[i] = (1 - p[i]) / p[i];
	}
	sum += product;
	float dp1[n];
	for (int i = 0; i < n; i++) {
		dp1[i] = product * divi[i];
		sum += dp1[i];
		//cout << dp1[i] << " ";
	}
	if (n < 5) {
		//sum of all calculated
		cout << sum;
	}
	else {
		float dp2[n / 2][n];
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (i == 0) {
						if (j != k)
							dp2[i][j] += dp1[k] * divi[j];
					}
					else {
						dp2[i][j]				=
					}
				}
			}
		}
	}

	return 0;
}