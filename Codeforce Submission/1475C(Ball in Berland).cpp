#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
inline ll nc2(ll n) {
    if (n < 2)
        return 0;
    return (n * (n - 1)) / 2;
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
        int n, m, k;
        cin >> n >> m >> k;
        int a[k], b[k];
        //counting frequency of girl and boy
        int a_ct[n + 1] = {0};
        int b_ct[m + 1] = {0};

        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a_ct[a[i]]++;
        }
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            b_ct[b[i]]++;
        }
        //total number of unique ways of selecting =kc2 (multiply by 1LL as (int)*(int)overflow)
        ll total = (k * 1LL * (k - 1)) / 2;

        for (int i = 1; i <= n; i++) {
            //boy appear more than one so chosing its ways which are nc2
            total -= (a_ct[i] == 0 ? 0 : nc2(a_ct[i]));
        }

        for (int i = 1; i <= m; i++) {
            //similary girls
            total -= (b_ct[i] == 0 ? 0 : nc2(b_ct[i]));

        }

        cout << total << endll;
    }
    return 0;
}