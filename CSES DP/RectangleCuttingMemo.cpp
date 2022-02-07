#include <bits/stdc++.h>
using namespace std;

#define    endl    "\n"
#define    SPEED      ios_base::sync_with_stdio(0); cin.tie(0);

int dp[501][501];
int solve(int a, int b) {
  if (a == b) return 1;
  if (a > b) swap(a, b);

  if(dp[a][b]!=-1) return dp[a][b];

  int ans = INT_MAX;
  for (int i = 1; i <b; i++) {
    ans = min(ans, solve(a, i) + solve(a, b - i));
  }
  for(int i=1;i<a;i++){
    ans=min(ans,solve(i,b)+solve(a-i,b));
  }
  return dp[a][b]=ans;
}
int main()
{
  SPEED;
  int a, b; cin >> a >> b;
  if (a < b) swap(a, b);
  memset(dp,-1,sizeof(dp));
  cout << solve(a, b) - 1;
  return 0;
}