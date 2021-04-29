#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

vector<vector<int>> graph;
vector<bool> visited;
int nodes, edges;
vector<int> dist;

vector<int> ansestor;

void bfs(int pt) {
  queue<int> q;
  dist[pt - 1] = 1;
  visited[pt - 1] = false;
  q.push(pt - 1);

  while (!q.empty()) {
    int k = q.front();
    q.pop();
    //cout << k + 1 << endl;
    for (auto i : graph[k]) {
      if (visited[i - 1]) {
        dist[i - 1] = dist[k] + 1;
        visited[i - 1] = false;
        q.push(i - 1);
        ansestor[i - 1] = k;
        //cout << " " << i << endl;
      }
    }
  }
  // for (auto i : ansestor)
  //   cout << i << " ";
}

void insert_element() {
  int x, y;
  for (int i = 0; i < edges; i++) {
    cin >> x >> y;
    graph[x - 1].push_back(y);
    graph[y - 1].push_back(x);
  }
}
void print_path(int end_pt) {
  if (ansestor[end_pt] == -1) {
    cout << end_pt + 1 << " ";
    return;
  }
  else {
    print_path(ansestor[end_pt]);
    cout << end_pt + 1 << " ";
  }
}
int main()
{
  FIO;
  cin >> nodes >> edges;
  graph.resize(nodes);
  visited.resize(nodes, true);
  insert_element();
  dist.resize(nodes, 0);
  ansestor.resize(nodes, -1);
  bfs(1);
  if (visited[nodes - 1]) {
    cout << "IMPOSSIBLE";
  }
  else {
    cout << dist[nodes - 1] << endl;
    //printing the path
    print_path(nodes - 1);
  }

  return 0;
}