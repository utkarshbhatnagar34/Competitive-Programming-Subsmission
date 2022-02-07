#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"
 
int N, M;
vector<int> visited;
vector<vector<int>> adj, adj_rev;
 
void input() {
    cin >> N >> M;
    adj.resize(N + 1);
    adj_rev.resize(N + 1);
    while (M--) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
        adj_rev[B].push_back(A);
    }
}
 
void dfs1(int src, vector<int> &order) {
    visited[src] = 1;
    for (auto child : adj[src])
        if (!visited[child])
            dfs1(child, order);
    order.push_back(src);
}
void dfs2(int src, vector<int> &component) {
    visited[src] = 1;
    component.push_back(src);
    for (auto child : adj_rev[src])
        if (!visited[child])
            dfs2(child, component);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    SPEED;
    input();
    visited.resize(N + 1);
    vector<int> order;
 
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            dfs1(i, order);
 
    reverse(order.begin(), order.end());
    visited.assign(N + 1, false);
 
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i;
 
    int cc = 1;
    for (auto i : order) {
        if (!visited[i]) {
            vector<int> component;
 
            dfs2(i, component);
 
            for (auto j : component)
                parent[j] = cc;
            cc++;
 
            component.clear();
        }
    }
    cout << max(cc - 1, 1) << endl;
    for (int i = 1; i <= N; i++) cout << parent[i] << " ";
    return 0;
}