#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M;
vector<vector<int>> adj;
vector<int> in;
//kahns algorithm

void toposort() {
  vector<int> result;

  queue<int> q;
  for (int i = 0; i < N; i++)
    if (in[i] == 0) q.push(i);


  while (!q.empty()) {
    int current = q.front();
    result.push_back(current+1);
    q.pop();

    for (auto child : adj[current]) {
      in[child]--;
      if (in[child] == 0) q.push(child);
    }
  }
  print(result);
  if (result.size() < N) {
    cout << "topo fails. Graph is cyclic" << endl; return;
  }

  print(result);
}
int main()
{
  SPEED;
  cin >> N >> M;
  adj.resize(N + 1);
  in.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin>>X>>Y;
    adj[X - 1].push_back(Y - 1);
    in[Y-1]++;
  }
  toposort();
  return 0;
}