#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
ll n;
ll a[100001], b[100001], c[100001];
ll dp[100001][4];//[number of days][maximum happiness in one day]
ll solve(int idx, int pre_task) {
    if (idx >= n)
        return 0;
    if (dp[idx][pre_task] != -1)
        return dp[idx][pre_task];

    ll ans = INT_MIN;
    if (pre_task == 1) {
        ans = max(ans, b[idx] + solve(idx + 1, 2));
        ans = max(ans, c[idx] + solve(idx + 1, 3));
    }
    else if (pre_task == 2) {
        ans = max(ans, a[idx] + solve(idx + 1, 1));
        ans = max(ans, c[idx] + solve(idx + 1, 3));
    }
    else if (pre_task == 3) {
        ans = max(ans, a[idx] + solve(idx + 1, 1));
        ans = max(ans, b[idx] + solve(idx + 1, 2));
    }
    else {
        ans = max(ans, a[idx] + solve(idx + 1, 1));
        ans = max(ans, b[idx] + solve(idx + 1, 2));
        ans = max(ans, c[idx] + solve(idx + 1, 3));
    }
    dp[idx][pre_task] = ans;
    return dp[idx][pre_task ];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endll;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cout << dp[i][j] << " ";
        cout << endll;
    }
    return 0;
}