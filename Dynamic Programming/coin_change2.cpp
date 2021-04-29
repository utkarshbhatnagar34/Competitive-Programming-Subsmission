#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
#define mod    1000000007

//coins change 2
int solve(int x, int coin[], int idx, int n) {

    if (x == 0)
        return 1;

    if (idx >= n || x < 0)
        return 0;

    int in, ex;
    in = solve(x - coin[idx], coin, idx, n);
    ex = solve(x, coin, idx + 1, n);
    return in + ex;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    //n->number of coins
    //x->required sum
    //c->coins
    //test case
    //3 5
    //2 3 5
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int ans = solve(x, c, 0, n);
    cout << ans << endl;
    //length of array
    int len = sizeof(c) / sizeof(*c);
    cout << "lenght=" << len << endl;
    return 0;
}