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
	FIO;
	int n;
	cin >> n;
	int a[n];
	int brek = 0, mn = INT_MAX;
	std::vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (mn > a[i])
			mn = a[i];
	}

	//2 3 4 1 1 1 3
	//brek should be one only,mn should be consicutive or at 0 and n-1
	int pos, k;
	if (a[0] == mn)
		v.push_back(0);
	k = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			if (brek == 0) {
				if (a[i] != mn)
					brek++;
			}
			brek++;
		}
		if (brek == 1) {
			if (k < a[i]) {
				brek++;
			}
		}

		if (a[i] == mn)
			v.push_back(i);
	}
	if (brek == 0)
		cout << 0;
	else if (brek == 1) {
		if (v[0] == 0) {
			for (int i = 0; i < v.size(); i++) {
				if (v[i] != v[i + 1] - 1 && i < n) {
					//cout << v[i] << " " << v[i + 1] << endll;
					pos = v[i + 1];
					break;
				}
			}
			cout << n - ( pos );
		}
		else {
			cout << n - v[0];
		}
	}
	else
		cout << -1;
	return 0;
}