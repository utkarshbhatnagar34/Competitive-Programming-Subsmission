#include<bits/stdc++.h>
using namespace std;
#define print(a){for(auto i:a) cout<<i<<" ";cout<<endl;}
int mod=1e9+7;

int main(void){
  int n,x;cin>>n>>x;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int dp[x+1]={0};
  dp[0]=1;

  for(int i=0;i<x;i++){
    if(i==0||dp[i]){
      for(int j=0;j<n;j++){
        if(i+a[j]<=x)
          dp[i+a[j]]=(dp[i+a[j]]+dp[i])%mod;
      }
    }
    //print(dp);
  }
  
  cout<<dp[x]<<endl;
}