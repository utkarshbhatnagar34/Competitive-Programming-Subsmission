#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, long long> pill;
typedef pair<long long, int> plli;

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

//nodes are from 1 to N directed Graph

int N, M;
vector<vector<int>> adj;
vector<int> in;

const ll INF = 1e15 + 7;

void input() {
   cin >> N >> M;
   adj.resize(N + 1);
   in.resize(N + 1);
   for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      //directed
      in[b]++;
      adj[a].push_back(b);
   }
}
//topological sort
void topological() {
   queue<int> q;
   for (int i = 1; i <=N; i++)
      if (in[i] == 0)
         q.push(i);

   vector<int> dist(N+1);
   while (q.size()) {
      int node = q.front(); q.pop();
      for (auto child : adj[node]) {
         in[child]--;
         if (in[child] == 0)
            q.push(child), dist[child] = dist[node] + 1;
      }
   }
  // print(dist);
   int ans = *max_element(dist.begin(), dist.end());
   cout << ans << endl;
}

int main()
{
   SPEED;
   input();
   topological();
   return 0;
}