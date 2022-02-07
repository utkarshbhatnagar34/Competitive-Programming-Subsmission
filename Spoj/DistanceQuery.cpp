#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*DISQUERY - Distance Query SPOJ
  used -lowerst common ancestor +binary lifting +sparse table
  Medium 
*/
#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"
const int INF = 1e7 + 5;

int N, LOG;
vector<vector<int>> adj, up, small, large;
map<pair<int, int>, int> mp;
vector<int> visited, parent, level;

void input() {
  cin >> N;
  adj.resize(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int A, B, W; cin >> A >> B >> W;
    adj[A].push_back(B);
    adj[B].push_back(A);
    mp[ {A, B}] = W; mp[ {B, A}] = W;
  }
  LOG = ceil(log2(N));
  up.resize(N + 1, vector<int>(LOG + 1));
  small.resize(N + 1, vector<int>(LOG + 1));
  large.resize(N + 1, vector<int>(LOG + 1));
  visited.resize(N + 1);
  parent.resize(N + 1);
  level.resize(N + 1);
}

void dfs(int src, int par) {
  visited[src] = 1;
  parent[src] = par;
  level[src] = level[par] + 1;

  for (auto child : adj[src]) {
    if (!visited[child])
      dfs(child, src);
  }
}

void preprocessing() {
  //doing dfs
  for (int i = 1; i <= N; i++)
    if (!visited[i]) dfs(i, 0);

  //makeing up
  for (int i = 1; i <= N; i++)
    up[i][0] = parent[i];

  for (int K = 1; K <= LOG; K++) {
    for (int i = 1; i <= N; i++)
      up[i][K] = up[ up[i][K - 1] ][K - 1];
  }

  //small
  for (int i = 1; i <= N; i++) {
    if (mp.find({i, up[i][0]}) != mp.end()) {
      small[i][0] = mp[ {i, up[i][0]}];
      large[i][0] = mp[ {i, up[i][0]}];
    }
    else
      small[i][0] = 0, large[i][0] = 0;
  }

  for (int K = 1; K < LOG; K++) {
    for (int i = 1; i <= N; i++) {
      small[i][K] = min(small[i][K - 1], small[up[i][K - 1]][K - 1]);
      large[i][K] = max(large[i][K - 1], large[up[i][K - 1]][K - 1]);
    }
  }

}
void lsc(int a, int b) {
  int smallest = INF, largest = 0;
  if (a == b) { cout << smallest << " " << largest << endl; return;}

  if (level[a] > level[b]) swap(a, b);
  // difference between levels =d
  int d = level[b] - level[a];

  while (d > 0) {
    int K = log2(d);
    smallest = min(smallest, small[b][K]);
    largest = max(largest, large[b][K]);
    b = up[b][K];
    d -= (1 << K);
  }

  if (a == b) {cout << smallest << " " << largest << endl; return;}
  //now d==0 both are on same level

  for (int K = LOG - 1; K >= 0; K--) {
    if (up[a][K] != 0 && up[a][K] != up[b][K]) {
      smallest = min({smallest, small[a][K], small[b][K]});
      largest = max({largest, large[a][K], large[b][K]});
      a = up[a][K]; b = up[b][K];
    }
  }

  smallest = min({smallest, small[a][0], small[b][0]});
  largest = max({largest, large[a][0], large[b][0]});
  cout << smallest << " " << largest << endl;
}
void query() {
  int Q; cin >> Q;
  while (Q--) {
    int U, V; cin >> U >> V;
    lsc(U, V);
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  SPEED;
  input();
  preprocessing();
  query();
  return 0;
}
