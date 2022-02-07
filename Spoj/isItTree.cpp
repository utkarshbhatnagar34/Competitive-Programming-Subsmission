#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m;
//detect cycle in undirected graph using dfs
bool dfs(int node, vector<bool> &visited, int parent) {
  visited[node] = 1;
  bool ans = 1;
  for (auto i : adj[node]) {
    if (i != parent &&  visited[i] == 1) return false;
    else if (visited[i] != 1) {
      ans = ans & dfs(i, visited, node);
    }
  }
  return ans;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  cin >> n >> m;
  adj.resize(n);

  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  vector<bool> visited(n); int connected = 0;
  bool ans = 1;
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      connected++;
      ans = dfs(i, visited, -1);
    }
    if (connected > 1) break;
  }
  if (ans == 1 && connected <= 1) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}