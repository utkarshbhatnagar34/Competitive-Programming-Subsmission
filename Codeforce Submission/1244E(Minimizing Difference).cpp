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
    //we actually not have to do operation we only want its end state
    //so L=1 and R=n and as L increases and R decreases
    //and check L is small or n-R
    int n; ll k;
    cin >> n >> k;
    int a[n + 1];
    a[0] = -1;
    //storing it in 1 to N format
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    int L = 1, R = n;
    ll temp;
    //as it is the initial difference and we have to minimize it
    int ans = a[R] - a[L];
    while (L < R) {
        temp = 0;
        if (L <= (n + 1) - R) {
            //their are 2 options
            //1 4 4 10and
            //k=2 so we can increases 1 atmost to 3 or drcreases ans by 3
            //k=9 so it become 4 4 4 10 and than increase by k/L
            temp = min(k / L, 1LL * (a[L + 1] - a[L]));
            ans -= temp;
            k -= 1LL * temp * L;
            L++;
        }
        else {
            temp = min(k / (n + 1 - R), 1LL * (a[R] - a[R - 1]));
            ans -= temp;
            k -= temp * 1LL * (n + 1 - R);
            R--;
        }
    }
    cout << ans;
    return 0;
}