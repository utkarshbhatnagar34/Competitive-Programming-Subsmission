#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
//========================================================
//if stuck first watch-https://www.youtube.com/watch?v=mVnt4eHFBfU&t=1512s
//than for better understandin-https://www.youtube.com/watch?v=ap-q_wQn7BE&t=1107s
//since a/b=a%b=r so r<=b-1 and
//equation can be modified into a=r(b+1)
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
		int x, y;
		cin >> x >> y;
		ll ans = 0;
		int b_max, b_min;
		//its complexcity is n^1/2
		for (int r = 1; r * (r + 2) <= x; r++) {
			//minimum value of b is r+1
			b_min = r + 1;
			//maximum value of b is either Y or (x/r)-1
			b_max = min(y, x / r - 1);
			ans += max(0, b_max - b_min + 1);
		}
		cout << ans << endll;
	}
	return 0;
}

//======================================
//b iterate from 2 to 10^9 and complexcity is O(n)
//As 2 seconds are given so in 1Sec=4*10^8 operation and in 2sec=2*4*10^8 operation
//but to pass the test case its complexcity should be O(n^1/2)
//so here we are a%b : let b=2 ,b=3,b=4,b=5 each of them have remainder so r is found using r a can be found
//b=2 have reminder 1 so r=1 ,a=r(b+1)=>3
//b=3 have two remainder 1,2 ,a=r(b+1)=>4,8
//b=4 have three remainder 1,2,3  a=r(b+1)=>5,10,15
//similarly we can find all possible pair of a,b using
// int t;
// 	cin >> t;
// 	while (t--) {
// 		int x, y;
// 		cin >> x >> y;
// 		ll ans = 0;
// 		inth a_max;
// 		for (int b = 2; b <= y; b++) {
// 			a_max = min(b - 1, x / (b + 1));
// 			ans += a_max;
// 		}
// 		cout << ans << endll;
// 	}
//=====================================
//it is the brute force implementation of the above problem but it O(n^2)so too slow
//better implementation is above
// cin >> x >> y;
// int ans = 0;
// ll mul = 1;
// for (int r = 1; r < y; r++) {
// 	for (int j = 1; j <= y ; j++) {
// 		mul = (j + 1) * 1ll * r;
// 		if (mul <= x) {
// 			if ((mul % j) == r) {
// 				//cout << mul << " " << j + 1 << endll;
// 				ans++;
// 			}
// 		}
// 		else
// 			break;
// 	}
// }