#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  vector<int>  dp(n+1,1e9);
  dp[0]=0;
  for(int i=1;i<n;i++){
    for(int j=1;j<=k&&i-j>=0;j++){
      dp[i]=min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
    }
  }
  cout<<dp[n-1];
}