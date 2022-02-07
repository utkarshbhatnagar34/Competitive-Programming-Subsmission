#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

vector<int> parent;
int largest = 0, component;

int find_parent(int child) {
    if (parent[child] < 0) return child;
    return parent[child] = find_parent(parent[child]);
}

void union_node(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a != b) {
        if (abs(parent[a]) >= abs(parent[b])) {
            parent[a] += parent[b];
            largest = max(largest, abs(parent[a]));
            parent[b] = a;
        }
        else {
            parent[b] += parent[a];
            largest = max(largest, abs(parent[b]));
            parent[a] = b;
        }
        component--;
    }
}
int main()
{
    SPEED;
    int N, M; cin >> N >> M;
    component = N;
    parent.resize(N + 1, -1);

    while (M--) {
        int A, B; cin >> A >> B;
        union_node(A, B);
        cout << component << " " << largest << endl;
    }
    return 0;
}