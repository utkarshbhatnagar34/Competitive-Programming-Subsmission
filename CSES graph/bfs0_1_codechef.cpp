#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// link -https://www.codechef.com/START28B/problems/TRAVELLING

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M;
const ll inf = 1e10 + 9;
vector<vector<pair<int, ll>>> adj;
vector<bool> visited;
vector<ll> dist;

void input() {
  cin >> N >> M;
  set<pair<int, int>> st;
  adj.clear();
  adj.resize(N + 1);
  while (M--) {
    int a, b; cin >> a >> b;
    adj[a].push_back({b, 0});
    adj[b].push_back({a, 0});
    st.insert({a, b}); st.insert({b, a});
  }
  for (int i = 2; i <= N; i++) {
    if (st.find({i, i - 1}) == st.end()) {
      adj[i].push_back({i - 1, 1});
      adj[i - 1].push_back({i, 1});
    }
  }
  dist.clear(); dist.resize(N + 1, inf);
  visited.clear(); visited.resize(N + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  SPEED;
  int T; cin >> T;
  while (T--) {
    input();
    //using 0 1 bfs
    deque<int> dq;
    dq.push_back(1);
    dist[1] = 0;
    while (!dq.empty()) {
      int node = dq.front(); dq.pop_front();
      visited[node] = 1;
      for (auto i : adj[node]) {
        int child = i.first, d = i.second;
        if (visited[child]) continue;

        if (dist[node] + d < dist[child]) {
          dist[child] = dist[node] + d;
          if (d == 1)
            dq.push_back(child);
          else
            dq.push_front(child);
        }
      }
    }

    cout << dist[N] << endl;
  }
  return 0;
}