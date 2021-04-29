#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int wi[n], li[n];
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> wi[i];
            m[wi[i]] = i;
        }
        for (int i = 0; i < n; i++)
            cin >> li[i];

        int ans = 0;
        map<int, int>::iterator itt = m.begin();
        int pre_pos = itt->second;
        itt++;
        int pos;

        for (map<int, int>::iterator it = itt; it != m.end(); it++) {
            pos = it->second;
            while (pos <= pre_pos) {
                pos += li[it->second];
                ans++;
            }
            pre_pos = pos;
        }
        cout << ans << endll;
    }
    return 0;
}