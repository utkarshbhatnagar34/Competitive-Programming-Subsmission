#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

const int mod = 1e9 + 7;
int n;
string s, str = "abc";
int dp[200001][4];

int solve(int i, int j) {
    if (i == n){
      return j==3;
    }
    if(j>3) return 0;
    if( dp[i][j]!=-1) return dp[i][j];

    if (s[i] != '?') {
        if (s[i] == str[j]) {
            return  dp[i][j]=(solve(i + 1,j + 1)%mod +0ll+ solve(i + 1, j)%mod)% mod;
        }
        return  dp[i][j]=solve(i + 1, j)%mod;
    }

    int ans = 0;
    for (char ch = 'a'; ch <= 'c'; ch++) {
        if (ch == str[j]) {
            ans = (ans%mod+solve(i + 1, j + 1)%mod +0ll+ solve(i + 1, j)%mod)%mod;
        }
        else ans = (ans%mod+0ll+solve(i + 1, j)%mod)%mod;
    }
    return dp[i][j]=ans;
}
int main()
{
    SPEED;
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);

    return 0;
}