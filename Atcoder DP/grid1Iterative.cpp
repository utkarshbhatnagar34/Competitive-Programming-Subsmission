#include<bits/stdc++.h>
using namespace std;

#define SPEED ios_base::syn_with_stdio(0);cin.tie(0);
const int mod=1e9 + 7;

int main(void){
  int N,M;cin>>N>>M;
  bool arr[N][M];
  int dp[N][M];memset(dp,0,sizeof(dp));

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      char ch;cin>>ch;
      if(ch=='.')
        arr[i][j]=true;
      else
        arr[i][j]=false;
    }
  }
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
       if(i-1>=0 && arr[i-1][j]) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
       if(j-1>=0 && arr[i][j-1]) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
    }
  }
  cout<<dp[N-1][M-1]<<endl;
}