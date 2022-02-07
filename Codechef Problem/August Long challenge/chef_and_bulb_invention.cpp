#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.in", "r", stdin);
	//freopen("output.in", "w", stdout);
#endif
	FIO;
	int t;
	cin >> t;
	while (t--) {
		int n, p, k; cin >> n >> p >> k;
		int pos = 0;
		--n;
		if ((n % k) < (p % k)) {
			pos += (n / k + 1) * ((n % k) + 1);

			int rem = p % k - ((n % k) + 1);
			pos += rem * (n / k);
		}
		else {
			int rem = p % k;
			pos += rem * (n / k + 1);
		}

		cout << pos + ((p - (p % k)) / k) + 1 << endl;
	}
	return 0;
}