#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int main(){
  //n-vertex m-edges
  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    adj[a-1].push_back(b);
    adj[b-1].push_back(a);
  }

  vector<int> visited(n),ansestor(n,-1);
  int found=0;

  for(int i=0;i<n;i++){
    if(visited[i]==0){
      queue<int> q;
      q.push(i);
      while(q.size()){
        int level=q.size();
        while(level--){
          int node=q.front();q.pop();
          if(node==n-1) {found=1;break;}
          for(auto child:adj[node]){
            if(visited[child-1]==0) 
              q.push(child-1);
              visited[child-1]=1;
              ansestor[child-1]=node;
          }
        }
        //if(found==1) break;
      }
    }
    break;
  }
  if(!found){
    cout<<"IMPOSSIBLE\n";return 0;
  }

  vector<int> seq;
  int node=n-1;
  while (node!=0||ansestor[node]!=node)
  {
    /* code */
  }
  
}