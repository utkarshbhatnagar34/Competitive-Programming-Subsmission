#include <bits/stdc++.h>
using namespace std;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int n,m;

vector<pair<int,int>> moves={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int getNode(int node,int i){
    node--;
    int x=node/m, y=node%m;
    int newx=x+moves[i].first, newy=y+moves[i].second;
    if(newx>=n || newx<0 || newy>=m || newy<0) return -1;
  
    int child=newx*m+newy;
    return child+1;
}

//considering 0 based indexing
void bfs(int start,int end,int &N,vector<vector<int>> &adj){
    queue<int> q;
    vector<int> parent(N+1,-1), dist(N+1,1e5);
    
    q.push(start); dist[start]=0;
    
    while(q.size()){
      int node=q.front(); q.pop();
      //cout<<"Start node "<<node<<endl;

      for(int i=0;i<8;i++){
        if(adj[node][i]==1){
          int child=getNode(node,i);
        
          if(dist[child]>dist[node]+1){
           
            dist[child]=dist[node]+1;
            parent[child]=node;
            q.push(child);
          }
        }
      }
    }

    int begin=end;

    while(parent[begin]!=-1){
      cout<<begin<<" ";
      begin=parent[begin];
    }
    cout<<start<<endl;
}
int main() {
	//input
  SPEED;
	cin>>n>>m;
	int start;cin>>start;
	
	int totalNodes=n*m;
	vector<vector<int>> adj(totalNodes+1,vector<int>(8));
	 
	for(int i=0;i<totalNodes;i++){
	    int node;cin>>node;
	    for(int j=0;j<8;j++){
	        cin>>adj[node][j];
	    }
	}
	
	
	//now starting my path from corners
	bfs(1,start,totalNodes,adj);
	bfs(m,start,totalNodes,adj);
	bfs((m*(n-1))+1,start,totalNodes,adj);
	bfs((n*m),start,totalNodes,adj);
	
	return 0;
}