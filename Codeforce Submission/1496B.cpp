#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
/*
eg:-

0 1 2
2+3/2=3
3+4/2=4


0 1 4

2+4/2=3
2+4/2=3
*/
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
		int n, k;
		cin >> n >> k;
		int a;
		multiset<int> s;
		set<int> dis;
		for (int i = 0; i < n; i++) {
			cin >> a;
			s.insert(a);
			dis.insert(a);
		}

		auto it = s.end();
		it--;
		int mx = *it;
		auto itr = s.begin();
		if (k > 0) {
			if (*itr == 0) {
				int j = 1;
				while (s.find(j) != s.end()) {
					j++;
				}
				if (j > mx) {
					cout << dis.size() + k;
				}
				else {
					dis.insert((j + mx + 1) / 2);
					cout << dis.size();
				}
			}
			else {
				int mex = 0;
				dis.insert((mx + 1) / 2);
				cout << dis.size();
			}
		}
		else
			cout << dis.size();
		cout << endll;
	}
	return 0;
}