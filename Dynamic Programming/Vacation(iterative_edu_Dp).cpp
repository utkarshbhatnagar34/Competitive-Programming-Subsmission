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
    //can do it with two 1D array =>one represent present day and the other previous(As done by erricto)
    ll day;
    cin >> day;
    int a[3];
    ll dp[day][3];
    memset(dp, 0, sizeof(dp));
    cin >> a[0] >> a[1] >> a[2];
    dp[0][0] = a[0]; dp[0][1] = a[1]; dp[0][2] = a[2];
    //cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << endll;
    for (int i = 1; i < day; i++) {

        cin >> a[0] >> a[1] >> a[2];
        for (int j = 0; j < 3; j++) {//present day=j
            for (int k = 0; k < 3; k++) {//previous day=k
                if (j != k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[j]);//each present day a[i] has 2 choices
                }
            }
        }
        //  cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endll;
    }
    cout << max(dp[day - 1][0], max(dp[day - 1][1], dp[day - 1][2]));
    return 0;
}