#include<bits/stdc++.h>
using namespace std;
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);
int N;
vector<double> prob;
double dp[3001][1600];
double solve(int idx,int maxTail){
  if(idx==N) return 1;
  if(dp[idx][maxTail]!=-1) return dp[idx][maxTail];
  if(maxTail==0){
    return solve(idx+1,maxTail)*prob[idx];
  }
  double op1=0,op2=0;
  op1=solve(idx+1,maxTail)*prob[idx];
  op2=solve(idx+1,maxTail-1)*(1-prob[idx]);

  return dp[idx][maxTail]=op1+op2;
}
int main(void){
  SPEED;
  for(int i=0;i<3001;i++)
    for(int j=0;j<1600;j++)
      dp[i][j]=-1;
    
  cin>>N;
  prob.resize(N);
  double multi=1;
  for(int i=0;i<N;i++){
   cin>>prob[i];multi*=prob[i];
  }
  
  int maxTail=N/2;
  double sum=solve(0,maxTail);
  cout<<setprecision(9)<<sum<<endl;
}