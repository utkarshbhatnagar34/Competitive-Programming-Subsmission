#include <bits/stdc++.h>
using namespace std;
//undirected graph using adjacency list
//dfs approach is much memory efficent than bfs
//time complexity is O(V+E)
int nodes, edges;
vector<vector<int>> adj;
vector<bool> visited;

//using node -1 means input must start form node zero
//using dfs
bool dfs(int start, int parent, bool visited[])
{
  visited[start] = 1;
  bool ans = 0;
  for (int i = 0; i < adj[start].size(); i++)
  {
    if (adj[start][i] != parent && visited[adj[start][i]] == 1)
      return true;
    else if (adj[start][i] != parent && visited[adj[start][i]] == 0)
    {
      ans = dfs(adj[start][i], start, visited);
      if (ans)
        return ans;
    }
  }
  return ans;
}

//using bfs
bool bfs(int start, int parent, bool visited[], vector<int> adj[])
{
  //node ,it parent
  queue<pair<int, int>> q;
  q.push({start, parent});
  bool ans = 0;
  while (q.size())
  {
    int current = (q.front()).first;
    parent = (q.front()).second;
    q.pop();
    visited[current] = 1;
    for (int i = 0; i < adj[current].size(); i++)
    {
      if (adj[current][i] != parent)
      {
        if (visited[adj[current][i]] == 1)
        {
          return true;
        }
        else
          q.push({adj[current][i], current});
      }
    }
  }
  return ans;
}

bool isCycle(int V)
{
  bool visited[V] = {0};
  bool ans = 0;
  for (int i = 0; i < V; i++)
  {
    if (visited[i] == 0)
    {
      //if use dfs to detect cycle
      ans = dfs(i, -1, visited);

      //if use bfs to detect cycle
      //ans=bfs(i,-1,visited);
      if (ans)
        return ans;
    }
  }
  return ans;
}
void insert_ele()
{
  int x, y;
  for (int i = 0; i < edges; i++)
  {
    cin >> x >> y;
    //for x starting form 1 to V
    // adj[x - 1].push_back(y);
    // adj[y - 1].push_back(x); //<-it should be removed in case of directed graph

    //for x starting from 0 to V-1
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

int main(void)
{
  cin >> nodes >> edges;
  adj.resize(nodes);
  visited.resize(nodes + 1, 0);
  insert_ele();
  cout << isCycle(nodes);
}