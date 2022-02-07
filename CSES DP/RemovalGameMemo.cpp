#include<bits/stdc++.h>
using namespace std;
long dp[5001][5001];
long solve(vector<long> &a,int l,int r){
  if(l>r) return 0;
  if(dp[l][r]!=-1) return dp[l][r];
  long op1=a[l]+0l+min(solve(a,l+2,r),solve(a,l+1,r-1));
  long op2=a[r]+0l+min(solve(a,l+1,r-1),solve(a,l,r-2));

  return dp[l][r]=max(op1,op2);
}
int main(){
  int n;cin>>n;
  vector<long> a(n);
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)
    cin>>a[i];

  cout<<solve(a,0,n-1);
}