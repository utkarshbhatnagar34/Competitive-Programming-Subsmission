#include<bits/stdc++.h>
using namespace std;

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);

int main(){
  SPEED;
  string s,t;
  cin>>s>>t;
  int n=s.size(),m=t.size();
  int dp[n+1][m+1];
  memset(dp,0,sizeof(dp));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s[i-1]==t[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  string str="";
  int i=n,j=m;
  
  while(i>0 && j>0){
    if(s[i-1]==t[j-1]){
      str+=s[i-1];i--;j--;
    }
    else if(dp[i-1][j]>=dp[i][j-1]){
      i--;
    }
    else{
      j--;
    }
  }
  reverse(str.begin(),str.end());
  cout<<str<<endl;
}