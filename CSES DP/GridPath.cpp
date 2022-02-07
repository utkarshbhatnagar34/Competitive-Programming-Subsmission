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
#define mod           1000000007
vector<pair<int, int>> vpi = {{1, 0}, {0, 1}};
int n;
int dp[1001][1001];

int solve(vector<vector<bool>> &a, int r, int c) {
    if (r == n - 1 && c == n - 1) return 1;
    if(dp[r][c]!=-1) return dp[r][c];
    int sum = 0;
    //cout<<r<<" "<<c<<endl;
    for (auto i : vpi) {
        int x = r + i.first, y = c + i.second;
        if (x<n&&y<n&&a[x][y])
            sum += solve(a, x, y);
    }
    return dp[r][c]=sum;
}
int main()
{
    FIO;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n));
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == '.') a[i][j] = 1;
        }
    }
    cout << solve(a, 0, 0);
    return 0;
}