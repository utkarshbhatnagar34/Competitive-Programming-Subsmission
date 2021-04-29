#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
int n1, n2;
int solve(string a, string b, string emp, int idx1, int idx2) {

	if (idx1 == n1 || idx2 == n2 || a.empty() || b.empty())
		return 0;

	if (a[idx1] == b[idx2]) {
		emp += a[idx1];
		cout << a[idx1];
		return solve(a, b, emp, idx1 + 1, idx2 + 1) + 1;
	}
	else {
		return max(solve(a, b, emp, idx1 + 1, idx2), solve(a, b, emp, idx1, idx2 + 1));
	}

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	n1 = a.length();
	n2 = b.length();
	string emp;
	cout << "ok";
	cout << solve(a, b, emp, 0, 0);
	return 0;
}