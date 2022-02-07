#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M;
vector<vector<int>> adj;
vector<int> visited;
vector<int> dist;
vector<int> child;

void dfs(int src) {
    visited[src] = 1;

    for (auto i : adj[src]) {
        if (visited[i] == 0) {
            dfs(i);
        }
        //since we only mark dist[N-1]=1 if it is impossible to reach the from 1 to N node than it will not update the distance 
        //as dist[i]=1 to update the distance which is only true in case of 
        if (dist[src] < dist[i] + 1 && dist[i] != 0) {
            //bottom to up store distance
            dist[src] = dist[i] + 1;
            child[src] = i;
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
    cin >> N >> M;

    adj.resize(N);
    visited.resize(N);
    child.resize(N, -1);
    dist.resize(N);


    while (M--) {
        int A, B; cin >> A >> B;
        adj[A - 1].push_back(B - 1);
    }
    //instead of top to bottom to store distance we move bottom to top
    dist[N - 1] = 1;
    dfs(0);
    if (dist[0] == 0) {
        cout << "IMPOSSIBLE\n";
    }
    cout << dist[0] << endl;
    int start = 0;
    while (child[start] != -1) {
        cout << start + 1 << " "; start = child[start];
    }
    cout << N;
    return 0;
}