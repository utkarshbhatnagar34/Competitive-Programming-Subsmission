#include <bits/stdc++.h>
using namespace std;

#define  endl           "\n"
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
//#define mod           1000000007
int n, m;
int dp[5001][5001];
int solve(string a, string b, int idx1, int idx2) {
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

    if (idx2 == m) {
        return n - (idx1);
    }

    int op1 = 0, op2 = 0, op3 = 0;
    if (idx1 == n) {
        return m - (idx2);
    }

    if (a[idx1] == b[idx2]) {
        return solve(a, b, idx1 + 1, idx2 + 1);
    }
    //add character in string a
    op1 = solve(a, b, idx1, idx2 + 1) + 1;

    //replace it
    op2 = solve(a, b, idx1 + 1, idx2 + 1) + 1;

    //delete it
    op3 = solve(a, b, idx1 + 1, idx2) + 1;

    return dp[idx1][idx2] = min(op1, min(op2, op3));
}
int main()
{
    FIO;
    string a, b; cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    n = a.size(); m = b.size();
    cout << solve(a, b, 0, 0);
    return 0;
}