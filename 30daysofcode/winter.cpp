#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M, Q;
int curTime = 0;
vector<int> frozen;
vector<vector<int>> adj;
queue<int> q;


void input() {
  adj.resize(N + 1);
  frozen.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

void query() {
  int type, node; cin >> type >> node;
  //print(frozen);
  if (type == 3) {
    if (frozen[node] == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  else if (type == 1) {
    if(frozen[node]==0){
      q.push(node); 
      frozen[node] = 1;
    }
  }
  else {
    int timepass = node;

    while (timepass > 0 && q.size()) {
      int len = q.size();

      while (len--) {
        int u = q.front();q.pop();
        frozen[u] = 1;
        for (auto child : adj[u]) {
          if(frozen[child]==0){
            frozen[child]=1;
            q.push(child);
          }
        }
      }
      timepass--;
    }
  }
}
int main()
{
  SPEED;
  cin >> N >> M >> Q;
  input();
  while (Q--) {
    query();
  }
  return 0;
}