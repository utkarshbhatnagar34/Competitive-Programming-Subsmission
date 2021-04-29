#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009

//2 5
//8 2 2 2 2

//2 7
//2 2 2 2 2
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	FIO;
	int n, k;
	cin >> n >> k;
	int four = n, two = n * 2, one = 0;
	int a, qui, rem;
	std::vector<int> v;
	bool flag = 1;
	for (int i = 0; i < k; i++) {
		cin >> a;
		if (a >= 3) {
			qui = a / 4;
			if (four >= qui) {
				four -= qui;
			}
			else if (two >= (2 * qui)) {
				two -= 2 * qui;
			}
			else {
				flag = 0; break;
			}
			rem = a % 4;
			if (rem != 0) {
				v.push_back(rem);
			}
		}
		else {
			v.push_back(a);
		}
	}
	if (v.size() == 0)
		cout << "YES";
	else if (flag) {
		sort(v.begin(), v.end(), greater<int>());
		int j = 0;
		if (four > 0 || two > 0) {
			while (j < v.size()) {
				//cout << v[j] << " " << j << endll;
				if (v[j] == 3) {
					if (four > 0) {
						four--;
					}
					else if (two > 1) {
						two -= 2;
					}
					else if (two > 0 && one > 1) {
						two--; one--;
					}
					else {
						flag = 0; break;
					}

				}
				else if (v[j] == 2) {
					if (two > 0) {
						two--;
					}
					else if (four > 0) {
						four--;
						one++;
					}
					else if (one >= 2) {
						one -= 2;
					}
					else {
						flag = 0; break;
					}

				}
				else {
					if (one > 0) {
						one--;
					}
					else if (two > 0) {
						two--;
					}
					else if (four > 0) {
						four--; two++;
					}
					else {
						flag = 0; break;
					}

				}
				v[j] = 0; j++;
			}
			//cout << four << " " << two << " " << one << endll;
			if (flag)
				cout << "YES";
			else
				cout << "NO";
		}
		else
			cout << "NO";
	}
	else
		cout << "NO";
	cout << endll;
	return 0;
}