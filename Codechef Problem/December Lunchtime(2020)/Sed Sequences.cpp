#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        ll s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % k == 0)
            cout << 0;
        else
            cout << 1;
        cout << endl;
    }
    return 0;
}
