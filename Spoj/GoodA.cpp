#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

ll N, M, S, E;
vector<ll> fun;
vector<ll> visited, parent;
vector<vector<ll>> adj, adj_rev, adjScc;
map<ll, ll> mp;

void create_graph() {
  cin >> N >> M >> S >> E;

  fun.resize(N + 1);
  for (ll i = 1; i <= N; i++)
    cin >> fun[i];

  adj.resize(N + 1);
  adj_rev.resize(N + 1);

  while (M--) {
    ll A, B; cin >> A >> B;
    adj[A].push_back(B);
    adj_rev[B].push_back(A);
  }
}
void dfs1(ll src, vector<ll> &order) {
  visited[src] = 1;
  for (auto child : adj[src]) {
    if (visited[child] == 0)
      dfs1(child, order);
  }
  order.push_back(src);
}
void dfs2(ll src, vector<ll> &connected, ll &totalfun) {
  visited[src] = 1;
  totalfun += fun[src];
  for (auto child : adj_rev[src]) {
    if (visited[child] == 0)
      dfs2(child, connected, totalfun);
  }
  connected.push_back(src);
}
void makeScc() {
  visited.resize(N + 1);
  vector<ll> order;

  for (ll i = 1; i <= N; i++) {
    if (visited[i] == 0)
      dfs1(i, order);
  }

  reverse(order.begin(), order.end());
  visited.assign(visited.size(), 0);

  parent.resize(N + 1);
  for (ll i = 0; i <= N; i++)
    parent[i] = i;

  for (auto i : order) {
    if (visited[i] == 0) {
      vector<ll> connected;
      ll totalfun = 0;

      dfs2(i, connected, totalfun);
      mp[i] = totalfun;

      for (auto j : connected)
        parent[j] = i;

      connected.clear();
    }
  }
}
void condensationGraph() {
  adjScc.resize(N + 1);
  for (ll i = 1; i <= N; i++) {
    for (auto child : adj[i]) {
      if (parent[i] != parent[child]) {
        adjScc[i].push_back(child);
      }
    }
  }

  // for (ll i = 1; i <= N; i++) {
  //   cout << i << " ->";
  //   for (auto child : adjScc[i]) {
  //     cout << child << " ";
  //   }
  //   cout << endl;
  // }
}

void dfs(ll src, vector<ll> &dp) {
  visited[src] = 1;
  for (auto i : adjScc[src]) {
    if (visited[i] == 0) {
      dfs(i, dp);
    }

    if (dp[src] < dp[i] + mp[src] && dp[i] != 0) {
      dp[src] = dp[i] + mp[src];
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  SPEED;
  create_graph();
  makeScc();
  condensationGraph();

  //mp contain the root and its fun value

  //since if we are on any node of a strongy connected component than we can visited all nodes of that
  S = parent[S];
  E = parent[E];

  //doing normal dfs
  vector<ll> dp(N + 1);
  visited.assign(visited.size(), 0);
  dp[E] = mp[E];

  dfs(S, dp);

  cout << dp[S] << endl;
  return 0;
}