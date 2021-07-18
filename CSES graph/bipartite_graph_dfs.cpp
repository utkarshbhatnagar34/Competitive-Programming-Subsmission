#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define endl "\n"
#define FIO                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<bool> vis;

//bipartite using dfs
bool dfs(int start, int c, int par)
{
  vis[start] = true;
  color[start] = c;

  for (auto i : adj[start])
  {
    if (i == par)
      continue;
    if (color[i] == 0)
      if (!dfs(i, !(color[start]), start))
        return false;
    if (color[i] == color[start])
      return false;
  }
  return true;
}

bool color_all()
{
  for (int i = 1; i <= n; ++i)
  {
    if (!vis[i])
      if (!dfs(i, 1, -1))
        return false;
  }
  return true;
}
int main()
{
  cin >> n >> m;
  adj.resize(n + 1);
  color.resize(n + 1);
  vis.resize(n + 1);

  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool ans = color_all();
  if (!ans)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i)
  {
    cout << (color[i] == 1 ? 1 : 2) << " ";
  }
}