#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endl     "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#define mod     1000000009
int mini(int a[], int j, int n) {
	int idx = j, mn = a[j];
	for (int i = j + 1; i < n; i++) {
		if (a[i] < mn) {
			mn = a[i];
			idx = i;
		}
	}
	return idx;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	FIO;
	int t;
	int test = 0;
	cin >> t;
	while (t--) {
		test++;
		int n;
		cin >> n;
		int a[n];
		int j, c;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int cost = 0;

		for (int i = 0; i < n - 1; i++) {
			j = mini(a, i, n);
			//cout << i + 1 << " " << j + 1 << endl;
			reverse(a + i, a + j + 1);
			cost += (j + 1) - (i + 1) + 1;
		}
		cout << "Case #" << test << ": " << cost << endl;
	}
	return 0;
}