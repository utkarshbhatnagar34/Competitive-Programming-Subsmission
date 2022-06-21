#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, long long> pill;
typedef pair<long long, int> plli;

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M;
vector<vector<pill>> adj;
const ll INF = 1e15 + 7;

void input() {
  cin >> N >> M;
  adj.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int a, b; ll c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
}
void output() {
  for (int i = 1; i <= N; i++) {
    cout << i << " ->\n";
    for (auto child : adj[i]) {
      cout << i << " " << child.first << " dist= " << child.second << endl;
    }
    cout << endl;
  }
}
void dijkstra() {
  vector<ll> dist(N + 1, INF);
  priority_queue<plli, vector<plli>, greater<plli>> minheap;
  vector<bool> visited(N + 1);

  dist[1] = 0;
  minheap.push({0, 1}); //dist,node

  while (minheap.size()) {
    int node = minheap.top().second; ll len = minheap.top().first;
    minheap.pop();
    visited[node] = 1;
    if (dist[node] < len) continue;

    for (auto i : adj[node]) {
      int child = i.first; ll d = i.second;
      if (visited[child]) continue;

      if (dist[child] > len + d) {
        dist[child] = len + d;
        minheap.push({dist[child], child});
      }
    }
  }

  for (int i = 1; i < dist.size(); i++)
    cout << dist[i] << " ";
}
int main()
{
  SPEED;
  input();
// output();
  dijkstra();
  return 0;
}