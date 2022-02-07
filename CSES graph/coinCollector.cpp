#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M;
vector<int> visited, root;
vector<ll> coin;
vector<vector<int>> adj, adj_rev, adjScc;
map<ll, ll> mp;

void input() {
    cin >> N >> M;
    adj.resize(N + 1);
    adj_rev.resize(N + 1);
    coin.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> coin[i];

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
void dfs2(int src, vector<int> &component, ll &totalCoin) {
    visited[src] = 1;
    component.push_back(src);
    totalCoin += coin[src];
    for (auto child : adj_rev[src])
        if (!visited[child])
            dfs2(child, component, totalCoin);
}

ll solve(int src, vector<ll> &dp) {
    if (dp[src]) return dp[src];

    dp[src] = mp[src];

    for (auto child : adjScc[src])
        dp[src] = max(dp[src], mp[src] + solve(child, dp));

    return dp[src];
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


    for (auto i : order) {
        if (!visited[i]) {
            vector<int> component;
            ll totalCoin = 0;
            dfs2(i, component, totalCoin);

            for (auto j : component)
                parent[j] = i;

            root.push_back(i);
            mp[i] = totalCoin;

            component.clear();
        }
    }

    //making condensation graph
    adjScc.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        for (auto child : adj[i]) {
            int root_i = parent[i];
            int root_child = parent[child];

            if (root_child != root_i)
                adjScc[root_i].push_back(root_child);
        }
    }

    visited.assign(N + 1, false);

    vector<ll> dp(N + 1);
    ll ans = 0;
    for (auto i : root) {
        ans = max(ans, solve(i, dp));
    }
    cout << ans << endl;
    return 0;
}