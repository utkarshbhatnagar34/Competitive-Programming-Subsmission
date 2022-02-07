#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M;
vector<vector<int>> adj, up;
vector<int> level;
int height;

void input() {
    cin >> N;
    adj.resize(N);
    level.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> M;
        while (M--) {
            int child; cin >> child;
            adj[i].push_back(child);
        }
    }
    height = ceil(log2(N));
    up.resize(N, vector<int>(height + 1, -1));
}
void dfs(int src) {
    for (auto child : adj[src]) {
        up[child][0] = src;

        for (int i = 1; i <= height; i++) {
            if (up[child][i - 1] > 0) up[child][i] = up[ up[child][i - 1] ] [i - 1];
        }

        level[child] = level[src] + 1;
        dfs(child);
    }
}

void printGraph() {
    for (int i = 0; i < N; i++) {
        cout << i << " ->";
        for (auto child : up[i])
            cout << child << " "; cout << endl;
    }
}

int lcs(int u, int v) {
    if (level[u] > level[v]) swap(u, v);

    int d = level[v] - level[u];

    while (d > 0) {
        int i = log2(d);
        v = up[v][i];
        d -= (1 << i);
    }

    if (u == v) return u;

    for (int i = height; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void query() {
    int Q; cin >> Q;
    while (Q--) {
        int A, B; cin >> A >> B;
        cout << lcs(A, B) << endl;
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
    level.resize(N);
    dfs(0);
    query();
    return 0;
}