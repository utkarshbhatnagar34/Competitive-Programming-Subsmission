#include<bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int ll;

int N,M;
vector<vector<pair<int,ll>>> adj;

void input(){
  cin>>N>>M;
  adj.resize(N+1);

  for(int i=0;i<M; i++){
    int u,v,c;cin>>u>>v>>c;
    adj[u].push_back({v,c});
  }
  
}
int main(void){
  :
}