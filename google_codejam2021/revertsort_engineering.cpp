#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endl     "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#define mod     1000000009

inline int find_ele(int a[], int ele, int n) {

	for (int i = 0; i < n; i++) {
		if (a[i] == ele) {
			return i;
		}
	}
	return 0;
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
		int n, c;
		cin >> n >> c;
		int a[n];
		for (int i = 0; i < n; i++)
			a[i] = i + 1;

		int mini_cost = n - 1;
		int max_cost = ((n * (n + 1)) / 2) - 1;
		if (c < mini_cost || c > max_cost) {
			cout << "Case #" << test << ": " << "IMPOSSIBLE" << endl;
		}
		else {
			int mn = 1;
			c -= mini_cost;
			int pt1 = 0, k = 0;
			while (c > 0) {
				if (c <= mini_cost) {
					if (k % 2 == 0) {
						reverse(a + pt1, a + pt1 + c + 1);
					}
					else {
						reverse(a + pt1 - c , a + pt1 + 1);
					}
					c = 0;
				}
				else {
					if (k % 2 == 0) {
						reverse(a + pt1, a + pt1 + mini_cost + 1);
					}
					else {
						reverse(a + pt1 - mini_cost, a + pt1 + 1);
					}
					c -= mini_cost;
					k++;
					mini_cost--;
					mn++;
					pt1 = find_ele(a, mn, n);
				}
			}
			cout << "Case #" << test << ": ";
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}
	return 0;
}