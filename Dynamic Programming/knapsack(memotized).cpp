#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
int dp[1001][100001];
int solve(int n, int p[], int hap[], int total, int idx) {

    if (idx > n)
        return 0;
    if (total == 0)
        return 0;
    if (dp[idx][total] != -1) {
        return dp[idx][total];
    }
    else {
        if (p[idx] <= total) {
            dp[idx][total] = max(hap[idx] + solve(n, p, hap, total - p[idx], idx + 1), solve(n, p, hap, total, idx + 1));
        }
        else {
            dp[idx][total] = solve(n, p, hap, total, idx + 1);
        }
        return dp[idx][total];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    int n, x;
    cin >> n >> x;
    int h[n], s[n];
    //h-price
    //s-pages/happiness
    //x->total
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)s
        cin >> s[i];

    //output maximum number of happiness
    cout << solve(n, h, s, x, 0);
    return 0;
}