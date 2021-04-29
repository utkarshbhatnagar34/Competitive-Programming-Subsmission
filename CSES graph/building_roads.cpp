#include <bits/stdc++.h>
using namespace std;
//undirected graph using adjacency list
//dfs for competitive programming
int nodes, edges;
vector<vector<int>> v;
vector<bool> b;
vector<int> city;

void insert_ele()
{
  int x, y;
  for (int i = 0; i < edges; i++)
  {
    cin >> x >> y;
    v[x - 1].push_back(y);
    v[y - 1].push_back(x); //<-it should be removed in case of directed graph
  }
}

//recurrsive
void dfs(int node)
{
  b[node] = 1;
  for (auto a : v[node])
  {
    if (b[a - 1] == 0)
    {
      //cout<<a<<endl;
      dfs(a - 1);
    }
  }
}
void connected_components()
{
  //it find number of independent graphs in the given graph
  int c = 0; //store connected components
  fill(b.begin(), b.end(), 0);
  for (int i = 0; i < nodes; i++)
  {
    if (b[i] == 0)
    {
      city.push_back(i + 1);
      dfs(i);
      c++;
    }
  }
  cout << c - 1 << endl;
  for (int i = 0; i + 1 < city.size(); i++)
  {
    cout << city[i] << " " << city[i + 1] << endl;
  }
}

void print_adj_list()
{
  //printing adjacency list
  for (int i = 0; i < nodes; i++)
  {
    cout << i + 1 << "-> ";
    for (int j = 0; j < v[i].size(); j++)
      cout << v[i][j] << " ";
    cout << endl;
  }
}

int main(void)
{
  cin >> nodes >> edges;
  int x, y;
  v.resize(nodes);
  b.resize(nodes + 1, 0);
  insert_ele();
  connected_components();
  //print_adj_list();
}