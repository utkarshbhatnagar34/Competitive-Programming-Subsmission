
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;   
typedef pair<int, int> pii;

#define  endl           "\n"
#define  all(v)         (v).begin(),(v).end()
#define  sz(v)          (int)(v).size()
#define  getunique(v)   {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  print(v)       {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
//#define mod           1000000007
int dp[1000001];
int inf = 1e7;
int solve(int n) {
    if (n < 0) return inf;
    if (n == 0)  return 0;
    if (dp[n] != -1) return dp[n];

    int op1 = inf, num = n;

    while (num > 0) {
        int d = num % 10;
        num /= 10;
        if (d == 0) continue;
        op1 = min(op1, solve(n - d) + 1);
    }

    dp[n] = op1;
    return dp[n];
}
int main()
{
    FIO;
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    cout << solve(n);
    return 0;
}