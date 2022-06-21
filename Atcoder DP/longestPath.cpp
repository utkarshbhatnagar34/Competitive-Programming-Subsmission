#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, long long> pill;
typedef pair<long long, int> plli;

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

//nodes are from 1 to N directed Graph

int N, M;
vector<vector<int>> adj;
vector<int> in,dist;
vector<bool> visited;

void input() {
   cin >> N >> M;
   adj.resize(N + 1);
   in.resize(N + 1);
   visited.resize(N+1);
   dist.resize(N + 1);
   for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      //directed
      in[b]++;
      adj[a].push_back(b);
   }
}
//using dfs
void dfs(int node){
  visited[node]=1;
  for(auto i: adj[node]){
    if(visited[i]){
      dist[node]=max(dist[node],dist[i]+1);
    }
    else{
      dfs(i);
      dist[node]=max(dist[node],dist[i]+1);
    }
  }
}

int main()
{
   SPEED;
   input();
   for(int i=1;i<=N;i++){
     if(!visited[i]){
       dfs(i);
     }
   }
   int ans=*max_element(dist.begin(),dist.end());
   cout<<ans<<endl;
   return 0;
}

