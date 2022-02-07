#include<bits/stdc++.h>
using namespace std;

int dp[101];
int solve(int idx,int target,vector<int> &a){
    if(target==0) return 1;
    if(idx==a.size()) return 0;
    //if(dp[idx]!=-1) return dp[idx];
    cout<<idx<<endl;
    int op1=0,op2=0;
    if(target>=a[idx])
      op1=solve(idx+1,target-a[idx],a);
    
    op2=solve(idx+1,target,a);
    cout<<idx<<" "<<target<<" "<<op1<<" "<<op2<<endl;
    return dp[idx]=op1+op2;
}
int findWays(vector<int> &num, int tar)
{
    memset(dp,-1,sizeof(dp));
    return solve(0,tar,num);
}

int main(){
  int n,target;cin>>n>>target;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<findWays(a,target);
  return 0;
}