#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  vector<int>  dp(n+1);
  for(int i=1;i<n;i++){
    int op1=1e7,op2=1e7;
    if(i-1>=0) op1=dp[i-1]+abs(a[i]-a[i-1]);
    if(i-2>=0) op2=dp[i-2]+abs(a[i]-a[i-2]);

    dp[i]=min(op1,op2);
  }
  cout<<dp[n-1];
}