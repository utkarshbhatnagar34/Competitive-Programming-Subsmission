#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (n < 10)
			cout << n;
		else {
			int copy = n;
			int fst;
			int val = 0;
			int place_val = 1;
			while (copy > 9) {
				copy /= 10;
				fst = copy;
				place_val *= 10;
				val++;
			}
			place_val *= fst;
			//cout << val << " " << place_val << " " << fst << endl;
			int p = 0;
			while (val) {
				place_val += fst * pow(10, p);
				//cout << fst * pow(10, p) << endl;
				p++;
				val--;
			}
			//cout << place_val << " " << p << "ok\n";
			if (n >= place_val)
			{
				cout << (9 * p + fst);
			}
			else
				cout << (9 * p  + fst - 1);
		}
		cout << endl;
	}
}
