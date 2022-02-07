#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
int n;
int dp[100001][3];
int solve(int day,int pre_choise){
  if(day==n) return 0;
  if(dp[day][pre_choise] != -1) return dp[day][pre_choise];

  int op1=0,op2=0,op3=0;
  if(pre_choise!=0) op1=a[day][0]+solve(day+1,0);

  if(pre_choise!=1) op2=a[day][1]+solve(day+1,1);

  if(pre_choise!=2) op3=a[day][2]+solve(day+1,2);

  return dp[day][pre_choise] =max({op1,op2,op3});
}
int main(){
  cin>>n;
  a.resize(n);
  for(int i=0;i<n;i++){
    a[i].resize(3);
    for(int j=0;j<3;j++) 
      cin>>a[i][j];
  }
  memset(dp,-1,sizeof(dp));
  int ans=0;
  for(int i=0;i<3;i++){
    ans=max(ans,solve(1,i)+a[0][i]);
  }
  cout<<ans;
}