#include<bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio;cin.tie(0);

int dp[10001][5];

int solve(int day,int prevTaken,int &K,vector<int> &A){
  if(day==K) return 0;
  if(dp[day][prevTaken]!=-1) return dp[day][prevTaken];

  int ans=INT_MAX;
  for(int i=1;i<=4;i++){
    if(day==0){
      ans=min(ans,solve(day+1,i,K,A));
    }
    else{
      if(A[day]>A[day-1]){
        if(i>prevTaken)
          ans=min(ans,solve(day+1,i,K,A));
        else
          ans=min(ans,solve(day+1,i,K,A)+1);
      }
      else if(A[day]<A[day-1]){
        if(i<prevTaken)
          ans=min(ans,solve(day+1,i,K,A));
        else
          ans=min(ans,solve(day+1,i,K,A)+1);
      }
      else{
        if(i==prevTaken)
         ans=min(ans,solve(day+1,i,K,A));
        else
         ans=min(ans,solve(day+1,i,K,A)+1);
      }
    }
  }
  return dp[day][prevTaken]=ans;
}
int main(){
  int T,test=1;cin>>T;
  while(T--){
    memset(dp,-1,sizeof(dp));
    int K;cin>>K;
    vector<int> A(K);

    for(int i=0;i<K;i++)
      cin>>A[i];

    int ans=solve(0,0,K,A);
    cout<<"Case #"<<test<<": "<<ans<<endl;
    ++test;
  }
}