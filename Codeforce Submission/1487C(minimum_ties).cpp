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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int win_i[n] = {0};
		//if n is odd than there is no ties and n/2 wins and n/2 loses
		if (n & 1) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (win_i[i] < n / 2) {
						win_i[i]++;
						cout << 1 << " ";
					}
					else {
						win_i[j]++;
						cout << -1 << " ";
					}
				}
			}
			//cout << win_i[0] << " " << win_i[1] << " " << win_i[2] << endll;
		}
		else {
			//even
			//than n/2-1 wins and 1 draw is requied
			int draw[n] = {0};
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (win_i[i] < (n / 2) - 1) {
						win_i[i]++;
						cout << 1 << " ";
					}
					else if (draw[i] == 0) {
						draw[i]++;
						draw[j]++;
						cout << 0 << " ";
					}
					else {
						win_i[j]++;
						cout << -1 << " ";
					}

				}
			}
		}
		cout << endll;
	}
	return 0;
}