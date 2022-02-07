#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*Range minimum query -SPOJ using sparse table*/

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, LOG;
vector<int> arr;
vector<vector<int>> m;

//finding values for powers of 2
void Rmq_preprocessing() {
    LOG = ceil(log2(N));
    m.resize(N, vector<int>(LOG + 1));
    //initialsing each for 2^0
    for (int i = 0; i < N; i++)
        m[i][0] = arr[i];

    //now finding remaining values
    for (int K = 1; K <= LOG; K++) {
        for (int i = 0; i + (1 << K) - 1 < N; i++) {
            m[i][K] = min(m[i][K - 1], m[i + (1 << (K - 1))][K - 1]);
        }
    }
}

void query() {
    int Q; cin >> Q;
    while (Q--) {
        int A, B; cin >> A >> B;
        int d = B - A + 1;
        d = log2(d);
        int smallest = min(m[A][d], m[B - (1 << d) + 1][d]);
        cout << smallest << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    SPEED;
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Rmq_preprocessing();
    query();
    return 0;
}
