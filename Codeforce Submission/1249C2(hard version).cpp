#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
ll power(ll a, ll b) {
	ll num = 1;
	while (b > 0) {
		if (b & 1)
			num *= a;
		a *= a;
		b /= 2;
	}
	return num;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		bool flag = true;
		ll num = n;
		ll pos = 0;
		int p_2 = -1;
		vector<ll> v;
		//finding the number is good number or not
		//if not than storing the positon of last 2 on its base 3 form
		//45=1200 in base 3 and to remove 2 we have to add greater number to it
		//so it becomes 11000
		while (num > 0) {
			if (num % 3 == 2) {
				flag = false;
				p_2 = pos;
			}
			v.push_back(num % 3);
			pos++;
			num /= 3;
		}
		if (flag)
			cout << n;
		else {
			//n=100201(in base 3)
			//so to remove 2 from it we have to add something to it since we have to make
			//the smallest number so which is good so we can remove all the digits after 2
			//and make 0 to 1 which occur left side of 2
			//ans=101000(answer in base 3)
			bool found = false; int one;
			for (int i = p_2 + 1; i < pos; i++) {
				if (v[i] == 0) {
					found = true;
					one = i;
					break;
				}
			}
			if (!found) {
				cout << power(3, pos);
			}
			else {
				ll sum = 0;
				sum += power(3, one);
				for (int i = one + 1; i < pos; i++) {
					if (v[i] == 1)
						sum += power(3, i);
				}
				cout << sum;
			}
		}
		cout << endll;
	}
	return 0;
}