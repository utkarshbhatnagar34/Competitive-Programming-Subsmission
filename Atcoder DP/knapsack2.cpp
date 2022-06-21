#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;   
const ll INF=1e18+7;

int main(){
  ll N, W;cin>>N>>W;
  ll sum=0;
  vector<ll> value(N);
  vector<ll> weight(N);

  for(int i=0;i<N;i++){ 
    cin>>weight[i]>>value[i];sum+=value[i];
  }
  
  vector<vector<ll>> dp(N+1,vector<ll>(100001,INF));
  //base case we are taking nothting with maximum weight
  dp[0][0]=0;
  dp[0][value[0]]=weight[0];
  
  for(ll i=1;i<N;i++){
    dp[i][0]=0;
    for(ll j=1;j<=100000;j++){
      dp[i][j]=dp[i-1][j];
      if(value[i]<=j)
        dp[i][j]=min(dp[i][j],dp[i-1][j-value[i]]+weight[i]);
    }
  }
  ll ans=0; 
  for(ll i=100000;i>=0;i--)
    if(dp[N-1][i]<=W){
      ans=i;break;
    }
  cout<<ans<<endl;
  return 0;
}