#include <bits/stdc++.h>
using namespace std;

#define  endl           "\n"
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
#define mod           1000000007
int x, n;
int dp[1000001];
int solve(vector<int> &a, int sum) {
    if (sum == x) return 1;
    if (sum > x) return 0;
    if (dp[sum] != -1) return dp[sum];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (solve(a, sum + a[i]) + ans) % mod;
    return dp[sum] = ans;
}
int main()
{
    FIO;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(a, 0);
    return 0;
}