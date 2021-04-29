#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

//help
//https://www.geeksforgeeks.org/sum-of-bitwise-and-of-all-subarrays/

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	FIO;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//number|number|number|number|number|number=number(means how many times bitwise or/and is performed but it only counts 1 time)
	//so in this question if any bit occur once in all the subarray it will added/or to the answer
	int ans = 0;
	int bit32[32] = {0};
	for (int i = 0; i < 32; i++) {
		int mul = (1 << i);

		for (int j = 0; j < n; j++) {
			if (a[j]&mul) {
				bit32[i]++;
			}
		}
	}
	for (int i = 0; i < 32; i++)
		cout << bit32[i] << " "; cout << endl;

	for (int i = 0; i < 32; i++) {
		if (bit32[i]) {
			ans += (1 << i);
		}
	}

	cout << ans;
	return 0;
}