#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

vector<vector<int>> adj;
vector<int> visited;
bool iscycle = 0;
int n, m;
stack<int> st;

void dfs(int node) {
    if (iscycle) return;

    visited[node] = 1;
    for (auto i : adj[node]) {
        if (visited[i] == -1)
            dfs(i);

        if (visited[i] == 1) {
            iscycle = 1; return;
        }
    }
    visited[node] = 0;
    st.push(node + 1);
}
void toposort() {
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            dfs(i);
        }
    }
}
int main()
{
    SPEED;
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, -1);

    while (m--) {
        int A, B; cin >> A >> B;
        adj[A - 1].push_back(B - 1);
    }
    toposort();
    if (iscycle) {
        cout << "IMPOSSIBLE" << endl; return 0;
    }

    while (st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}