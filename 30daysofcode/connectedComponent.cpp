#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
void dfs(int node,vector<int> &visited){
  visited[node]=1;
  for(auto child:adj[node]){
    if(visited[child-1]==0){
      dfs(child-1,visited);
    }
  }
}
int main(){
  int n,m;cin>>n>>m;
  //n-vertex m-edges 
  adj.clear();
  adj.resize(n);
  
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    adj[a-1].push_back(b);
    adj[b-1].push_back(a);
  }

  vector<int> visited(n);
  int connectedComponent=-1;
  vector<int> ans;
  for(int i=0;i<n;i++){
    if(visited[i]==0){
      dfs(i,visited);
      connectedComponent++;
      ans.push_back(i);
    }
  }
  cout<<connectedComponent<<endl;
  for(int i=0;i<ans.size()-1;i++){
    cout<<ans[i]+1<<" "<<ans[i+1]+1<<endl;
  }
}