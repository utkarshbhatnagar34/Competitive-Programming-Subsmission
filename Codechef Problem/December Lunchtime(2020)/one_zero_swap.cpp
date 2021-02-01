#include <bits/stdc++.h>
using namespace std;
#define ll       long long
#define endl     "\n"
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
		int one_p = 0, one_s = 0;//number of 1's in s and p
		char s[n], p[n];
		int ocu_s[n], ocu_p[n];//postion of ocuurence of one in both s and p
		int k = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> s[j];
			if (s[j] == '1') {
				one_s++;
				ocu_s[k] = j;
				k++;
			}
		}
		k = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> p[j];
			if (p[j] == '1') {
				one_p++;
				ocu_p[k] = j;
				k++;
			}
		}
		if (one_p == one_s) {

			sort(ocu_s, ocu_s + k);
			sort(ocu_p, ocu_p + k);
			int c = 0;
			if (one_s == 0)
				//if all are zero
				cout << "Yes";
			else {
				for (int i = 0; i < one_p; i++) {
					//if positon of 1's of s <= position of 1's of p
					if (ocu_s[i] <= ocu_p[i]) {
						c++;
					}
					else {
						c = 0;
						break;
					}
				}
				if (c == one_s)
					cout << "Yes";
				else
					cout << "No";
			}
		}
		else
			cout << "No";

		cout << endl;
	}
	return 0;
}