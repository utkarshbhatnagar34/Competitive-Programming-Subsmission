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
//#define mod    1000000009

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<bool> vis;


int main()
{
  FIO;
  cin >> n >> m;
  adj.resize(n + 1);
  color.resize(n + 1);
  vis.resize(n + 1);
  
  //input graph
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  
  return 0;
}