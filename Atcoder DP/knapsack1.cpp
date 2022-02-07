#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void){
  int N,W;cin>>N>>W;
  vector<ll> weight(N),value(N);
  
  for(int i=0;i<N;i++) cin>>weight[i]>>value[i];
  
  vector<vector<ll>> dp(N+1,vector<ll>(W+1));

  for(int i=1;i<=N;i++){
    for(int j=1;j<=W;j++){
      if(weight[i])
    }
  }
  return 0;
}