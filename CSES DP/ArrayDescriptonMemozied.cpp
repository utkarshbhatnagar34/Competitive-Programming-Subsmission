#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  endl           "\n"
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
#define mod           1000000007
int n, m;
bool isvalid1(int i, int next) {
    if (next == 0) return true;
    return (i <= (next + 1));
}
bool isvalid2(int pre, int i, int next) {
    if (pre == 0) return true;
    if (next == 0) {
        return (abs(i - pre) <= 1);
    }
    return ((abs(pre - i) <= 1) && (abs(i - next) <= 1));
}
int dp[100001][101];
int solve(vector<int> &a, int pre, int idx) {
    if (idx == n) return 1;
    if (dp[idx][pre] != -1) return dp[idx][pre];

    ll sum = 0;

    if (a[idx] != 0) return solve(a, a[idx], idx + 1);

    if (a[idx] == 0) {
        if (idx < n - 1) {
            int start = max(1, pre - 1);
            for (int i = start; i <= m && isvalid1(i, a[idx + 1]); i++) {
                if (isvalid2(pre, i, a[idx + 1])) {
                    sum = (sum + solve(a, i, idx + 1)) % mod;
                }
            }
        }
        else {
            int start = max(1, pre - 1);
            for (int i = start; i <= m && abs(i - pre) <= 1; i++) {
                sum = (sum + solve(a, i, idx + 1)) % mod;
            }
        }
    }
    dp[idx][pre] = sum;
    return dp[idx][pre];
}
int main()
{
    FIO;
    cin >> n >> m;
    vector<int> a(n);
    bool nozero = 1;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && a[i] != 0 && a[i - 1] != 0 && abs(a[i] - a[i - 1]) > 1) {
            cout << 0 << endl;
            return 0;
        }
        if (a[i] == 0) nozero = 0;
    }
    if (nozero) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1) {
        if (a[0] != 0) {
            cout << 1 << endl;
        }
        else {
            cout << m << endl;
        }
        return 0;
    }
    cout << solve(a, 0, 0) << endl;
    return 0;
}