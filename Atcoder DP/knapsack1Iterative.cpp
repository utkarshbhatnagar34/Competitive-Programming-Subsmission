#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int ll;

int main(){
  int N,W;cin >> N >> W;
  vector<int> weight(N),value(N);
  for(int i=0;i<N;i++)
    cin>>weight[i]>>value[i];

  vector<vector<ll>> dp(N+1,vector<ll>(W+1));
  //dp[ith weight taken with a value][for w Kg of weight]=min(dp[i-1][w],dp[i-1][W-w])

  for(int i=1;i<=N;i++){
    for(int j=0;j<=W;j++){
      if(weight[i-1]<=j)
       dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
      else
       dp[i][j] = max(dp[i][j],dp[i-1][j]);
    }
  }
  
  cout<<dp[N][W]<<endl;
}