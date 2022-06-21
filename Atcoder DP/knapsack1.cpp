#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> weight,value;
ll dp[101][100001];

ll solve(int idx,int W){
  int N=weight.size();
  if(W<=0) return 0;
  if(idx==N) return 0;
  if(dp[idx][W]!=-1) return dp[idx][W];

  ll op1=0,op2=0;
  if(W-weight[idx]>=0)
    op1= solve(idx+1,W-weight[idx])+value[idx];

  op2=solve(idx+1,W);

  return dp[idx][W]=max(op1,op2);
}
int main(void){
  int N,W;cin>>N>>W;
  memset(dp, -1, sizeof(dp));
  weight.resize(N);value.resize(N);
  for(int i=0;i<N;i++) 
    cin>>weight[i]>>value[i];
  
  cout<<solve(0,W);
  return 0;
}