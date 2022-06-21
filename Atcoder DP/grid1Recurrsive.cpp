#include<bits/stdc++.h>
using namespace std;
#define SPEED iso_base::sync_with_stdio(0);cin.tie(0);
const int mod=1e9 + 7;

vector<pair<int,int>> moves={{1,0},{0,1}};
int N,M;
bool valid(int x,int y){
  if(x>=0 && x<N && y>=0 && y<M) return true;
  return false;
}
int dp[1001][1001];

int solve(int x,int y,vector<vector<bool>> &arr){
  if(x==N-1 && y==M-1) return 1;
  if(x>=N || y>=M) return 0;
  if(dp[x][y]!=-1) return dp[x][y];  
  int ans=0;
  for(auto i:moves){
    int a=x+i.first,b=y+i.second;
    if(valid(a,b) && arr[a][b]){
       ans=(ans+solve(a,b,arr))%mod;
    }
  }
  return dp[x][y]=ans;
}
int main(){
  cin>>N>>M;
  memset(dp,-1,sizeof(dp));
  vector<vector<bool>> arr(N,vector<bool>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      char ch;cin>>ch;
      if(ch=='.') arr[i][j]=1;
    }
  }

  cout<<solve(0,0,arr)<<endl;
}