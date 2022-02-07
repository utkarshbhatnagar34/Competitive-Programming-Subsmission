#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define print(a){for(auto i:a) cout<<i<<" ";cout<<endl;}

int main(void){
  int n,x;cin>>n>>x;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  int dp[x+1]={0};
  dp[0]=1;

  for(int i=0;i<n;i++){
    for(int j=0;j<x;j++){
      if(j+a[i]<=x){
        dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
      }
    }
  }
  //print(dp);
  cout<<dp[x]<<endl;
  return 0;
}