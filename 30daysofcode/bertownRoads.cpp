#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

vector<vector<int>> adj;
vector<int> visited, in, low;
int timer = 0, bridge = 0;
vector<pair<int, int>> path;
vector<pair<int, int>> backedge;

void dfs(int node, int parent) {
  visited[node] = 1;
  in[node] = low[node] = timer++;

  for (auto i : adj[node]) {
    if (i == parent) continue;

    if (visited[i]) {
      //its a back edge
      if (in[node] > in[i])//to know who is the ansistor
        backedge.push_back({node, i});

      low[node] = min(low[node], in[i]);
    }
    else {
      dfs(i, node);
      path.push_back({node, i});

      if (low[i] > in[node]) bridge++;

      low[node] = min(low[node], low[i]);
    }
  }
}

int main()
{
  SPEED;
  int N, M; cin >> N >> M;
  adj.resize(N + 1); visited.resize(N + 1);
  in.resize(N + 1); low.resize(N + 1);

  while (M--) {
    int a, b; cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  dfs(0, -1);
  if (bridge) {cout << 0; return 0;}
  for (auto i : path) {
    cout << i.first + 1 << " " << i.second + 1 << endl;
  }

  for (auto i : backedge)
    cout << i.first + 1 << " " << i.second + 1 << endl;
  return 0;
}