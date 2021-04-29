#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009

//eg:-
//acbkegca k=1 a1+a2+r(a1)  a1=ac a2=bkeg
//after deleting one continious string(a2=bkeg) it should be palindrome
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
		string s;
		cin >> s;
		if (k == 0)
			cout << "YES";
		else {
			//k+1+k
			if ((2 * k) + 1 > n)
				cout << "NO";
			else {
				bool flag = 1;
				int match = 0;
				for (int i = 0; i < n ; i++) {
					if (s[i] != s[n - i - 1]) {
						flag = 0;
						break;
					}
					else
						match += 2;
				}
				//cout << match << endll;

				if (2 * k <= match)
					cout << "YES";
				else
					cout << "NO";

			}
		}
		cout << endll;
	}
	return 0;
}