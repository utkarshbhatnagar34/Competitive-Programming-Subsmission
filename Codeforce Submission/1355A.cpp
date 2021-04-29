#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
int operation(ll a) {
    string s = to_string(a);
    sort(s.begin(), s.end());
    //cout << s << endll;
    int mn = s[0] - '0';
    int mx = s[s.length() - 1] - '0';
    //cout << mn << " " << mx  << endll;
    return mn * mx;
}
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
        ll a1, k;
        cin >> a1 >> k;
        ll pre = a1;
        ll ans = a1;
        for (int i = 2; i <= k; i++) {
            int x = operation(pre);
            if (x != 0)
                ans = pre + x;
            else
                break;
            pre = ans;
        }
        cout << ans << endll;
    }
    return 0;
}