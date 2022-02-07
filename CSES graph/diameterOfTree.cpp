#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;
int maxdist = 0, diameterNode = 0;//diameterNode store the end pt of diameter node

int dfs(int node, vector<bool> &visited, int dist) {
  visited[node] = 1;
  if (maxdist <= dist) {
    maxdist = dist;
    diameterNode = node;
  }
  int ans = 0;
  for (auto child : adj[node]) {
    if (visited[child] == 0) {
      ans = max(ans, dfs(child, visited, dist + 1) + 1);
    }
  }
  return ans;
}
int main() {
  cin >> n;
  adj.resize(n);
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  vector<bool> visited(n);
  dfs(0, visited, 0); //return nunmber of nodes visited

  for (int i = 0; i < n; i++) visited[i] = 0;

  cout << dfs(diameterNode, visited, 0);
}