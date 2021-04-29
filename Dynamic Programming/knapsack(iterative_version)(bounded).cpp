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
    int n, x;
    cin >> n >> x;
    int h[n + 1], s[n + 1];
    //h-memory
    //s-value
    //x->total
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    //maximum number of different items,total amount of money that can be spend
    int dp[n + 1][x + 1];//
    memset(dp, 0, sizeof(dp)); //only 0 and -1 are allowed
    //dp[i][x] = maximum number of pages we can get for price at most x, only buying among the first i books
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j < h[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
        }
    }
    cout << dp[n][x];
    return 0;
}