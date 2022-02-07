#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define  endl           "\n"
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
//#define mod           1000000007
 
int n, x;
int inf = 1e6 + 1;
int dp[1000001];//used 1D dp
int solve(vector<int> &a, int sum) {
    if (sum == x) return 0;
    if (sum > x) return inf;
    if (dp[sum] != -1) return dp[sum];
 
    int ans = inf;
    for (int i = 0; i < n; i++)
        ans = min(ans, solve(a, sum + a[i]) + 1);
 
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
    int ans = solve(a, 0);
    if (ans == inf) cout << -1 << endl;
    else  cout << ans << endl;
    return 0;
}