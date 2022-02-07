#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &visited){
        visited[node]=1;//on
        int ans=0;
        for(auto i:adj[node]){
            if(visited[i]==-1){
                ans=ans|dfs(i,adj,visited);
                if(ans) return ans;
            }
            else if(visited[i]==1){
                return 1;
            }
        }
        visited[node]=0;//off
        return ans;
    }
    bool isCyclic(int V, vector<vector<int>> &adj) {
        int ans=0;
        vector<int> visited(V+1,-1);
        //-1 not visited , 0->dead , 1->on it 
        for(int i=0;i<V;i++){
            ans=ans|dfs(i,adj,visited);
        }
        return ans;
    }
};

int main(){
  int V,E;
  //V-vertix,E edges
  cin>>V>>E;
  vector<vector<int>> adj;
  for(int i=0;i<E;i++){
    int a,b;
    cin>>a>>b;
    adj[a-1].push_back(b-1);
  }
  Solution ob;
  cout<<ob.isCyclic(V,adj);
}