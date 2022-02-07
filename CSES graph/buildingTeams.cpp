#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m;

bool dfs(int node, vector<int> &visited, int parent) {
  visited[node] = 1 ^ parent;
  bool ans = 1;
  for (auto i : adj[node]) {
    if (visited[i] == -1) {
      ans = ans & dfs(i, visited, visited[node]);
    }
    else if (visited[i]^visited[node] == 0) {
      return false;
    }
  }
  return ans;
}
int main() {

  cin >> n >> m;
  adj.resize(n);

  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  vector<int> visited(n + 1, -1);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (visited[i] == -1) {
      ans = ans & dfs(i, visited, 0);
    }
  }
  if (ans == 0) {
    cout << "IMPOSSIBLE" << endl; return 0;
  }
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0)
      cout << 2 << " ";
    else
      cout << 1 << " ";
  }
  return 0;
}