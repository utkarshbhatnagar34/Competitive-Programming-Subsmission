#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int dfs(int node,int parent,vector<int> &color){
  color[node]=parent^1;
  for(auto child: adj[node]){
    if(color[child]!=-1)
      dfs()
  }
}

int main(){
  int n,m;cin>>n>>m;

  adj.resize(n);
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }

  //bipartite
  vector<int> color(n,-1);
  for(int i=0;i<n;i++){
    if(color[i]==-1){
      if(dfs(i,color)==0) break;
    }
  }
}