#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m, start = 0;
//detect cycle in it
bool dfs(int node, vector<bool> &visited, vector<int> &parent) {
  visited[node] = 1;
  int ans = 0;
  for (auto i : adj[node]) {
    if (parent[node] != i && visited[i] == 1) {
      start = node;
      parent[i] = node;
      return 1;
    }
    else if (visited[i] == 0) {
      parent[i] = node;
      ans = ans | dfs(i, visited, parent);
      if (ans) return ans;
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

  vector<bool> visited(n);
  vector<int> parent(n, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      int t = dfs(i, visited, parent);
      ans = ans | t;

      if (ans) break;
    }
  }

  if (ans) {
    int b = start;
    vector<int> ans;
    while (parent[b] != start) {
      ans.push_back(b + 1);
      b = parent[b];
    }
    ans.push_back(b + 1); ans.push_back(start + 1);
    cout << ans.size() << endl;

    for (auto i : ans)
      cout << i << " ";
    cout << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}