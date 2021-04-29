#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009A row in the airplane


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    int n, q, k;
    cin >> n >> q >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        x - 1; y - 1;
        int one = 0, two = 0;
        one = a[x - 1] - 1 + k - a[y - 1];
        two = (a[y - 1] - a[x - 1]) - (y - x);
        //cout << one << " " << two << endll;
        ll ans = one + (2 * two);
        cout << ans << endll;
    }
    return 0;
}