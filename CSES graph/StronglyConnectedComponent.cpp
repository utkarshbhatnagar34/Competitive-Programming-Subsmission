#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

//nodes start for 1 to N in it

int N, M;
vector<vector<int>> adj, adj_rev;
vector<int> visited;

void createGraph() {
  cin >> N >> M;
  adj.resize(N + 1);
  adj_rev.resize(N + 1);
  while (M--) {
    int U, V;
    cin >> U >> V;
    adj[U].push_back(V);
    adj_rev[V].push_back(U);
  }
}
//for finding and storing out time 
void dfs1(int src, vector<int> &order) {
  visited[src] = 1;
  for (auto child : adj[src]) {
    if (visited[child] == 0)
      dfs1(child, order);
  }
  order.push_back(src);
}

//storing the strongly connected components in the component vector
void dfs2(int src, vector<int> &component) {
  visited[src] = 1;
  component.push_back(src);
  for (auto child : adj_rev[src]) {
    if (visited[child] == 0)
      dfs2(child, component);
  }
}

int main()
{
  SPEED;
  createGraph();
  visited.resize(N + 1);
  vector<int> order;

  for (int i = 1; i <= N; i++) {
    if (visited[i] == 0)
      dfs1(i, order);
  }
  //order contain the element with increaseing order of out time
  //print(order);
  reverse(order.begin(), order.end());

  visited.assign(N + 1, false);

  vector<int> roots(N + 1), root_nodes;

  for (auto i : order) {
    if (visited[i] == 0) {
      vector<int> component;
      dfs2(i, component);

      roots[i] = i;
      for (auto j : component)
        roots[j] = i;

      root_nodes.push_back(i);

      component.clear();
    }
  }
  //it contain the root of each strongly connected component
  print(root_nodes);
  //it contains the node with root of its strongly connected component
  print(roots);

  //making Condensation Graph
  vector<vector<int>> adj_Scc(N + 1);

  for (int i = 1; i <= N; i++) {

    for (auto child : adj[i]) {
      //storing root/parent each ith node and its connected node
      int root_u = roots[i];
      int root_v = roots[child];

      //if there parent are not same than they are from two different strong connected component
      if (root_v != root_u) {
        adj_Scc[root_u].push_back(root_v);
      }

    }
  }

  for (int i = 1; i <= N; i++) {
    if (adj_Scc[i].size()) {
      cout << i << " ->";
      for (auto child : adj_Scc[i]) {
        cout << child << " ";
      }
      cout << endl;
    }
  }

  return 0;
}