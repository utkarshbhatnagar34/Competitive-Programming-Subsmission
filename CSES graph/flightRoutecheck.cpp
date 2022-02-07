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

    vector<int> order;
    visited.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            dfs1(i, order);
    }

    reverse(order.begin(), order.end());
    visited.assign(N + 1, false);

    vector<int> roots;
    for (auto i : order) {
        if (!visited[i]) {
            vector<int> component;

            dfs2(i, component);
            roots.push_back(i);
            component.clear();
        }
    }
    if (roots.size() > 1) {
        cout << "NO" << endl;
        /*reverse order of printing as we have traverse transpose array it shows that there is
        no edge between root[0] to root[1] since its a tanspose so in actual graph there is no between root[1] to root[0]*/
        cout << roots[1] << " " << roots[0] << endl;
    }
    else
        cout << "YES" << endl;
    return 0;
}