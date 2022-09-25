#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int n, q;
vector<ll> a, tree;

ll segSum(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
    if (queryLeft <= nodeLeft && nodeRight <= queryRight)
        return tree[node];
    if (nodeRight < queryLeft || queryRight < nodeLeft)
        return 0;

    int lastLeft = (nodeLeft + nodeRight) / 2;
    return segSum(2 * node, nodeLeft, lastLeft, queryLeft, queryRight) +
           segSum(2 * node + 1, lastLeft + 1, nodeRight, queryLeft, queryRight);
}

void updatePoint(int node, int nodeLeft, int nodeRight, int index, int val) {
    if (nodeLeft == nodeRight) {
        tree[node] = val; return;
    }

    int lastLeft = (nodeLeft + nodeRight) / 2;

    if (index <= lastLeft) updatePoint(node * 2, nodeLeft, lastLeft, index, val);
    else                   updatePoint(node * 2 + 1, lastLeft + 1, nodeRight, index, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void buildTree(int node, int left, int right) {
    if (left == right) {
        tree[node] = a[right]; return;
    }
    int lastLeft = (left + right) / 2;

    buildTree(2 * node, left, lastLeft); buildTree(2 * node + 1, lastLeft + 1, right);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
    SPEED;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (__builtin_popcount(n) != 1) n++;
    tree.resize(2 * n);

    buildTree(1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;
            //0 indexed array
            updatePoint(1, 0, n - 1, k - 1, u);
        }
        else {
            int left, right; cin >> left >> right;
            //0 indexed
            cout << segSum(1, 0, n - 1, left - 1, right - 1) << endl;
        }
    }
    return 0;
}