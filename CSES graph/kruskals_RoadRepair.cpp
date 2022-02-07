#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

struct edge {
    int u, v;
    ll w;
};
bool comp(edge a, edge b) {
    return a.w <= b.w;
}
int N, M;
vector<int> parent;
vector<edge> a;

void input() {
    cin >> N >> M;
    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        a.push_back({U, V, W});
    }
    //sorting on basis of edge weight
    sort(a.begin(), a.end(), comp);
}
int find_parent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find_parent(parent[node]);
}

int main()
{
    SPEED;
    input();

    //applying kruskals using disjointed set
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++)
        parent[i] = i;

    ll smallestCost = 0;
    for (auto i : a) {
        int u = i.u, v = i.v;
        ll  w = i.w;

        u = find_parent(u);
        v = find_parent(v);
        if (u != v) {
            smallestCost += w;
            parent[u] = v;
        }
    }
    int flag = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) flag++;
    }
    if (flag == 1)
        cout << smallestCost << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}