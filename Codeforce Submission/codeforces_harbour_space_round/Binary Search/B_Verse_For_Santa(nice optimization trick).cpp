#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in", "r", stdin);
   // freopen("output.in", "w", stdout);
#endif
    FIO;
    int t;
    cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        ll a[n];
        vector<ll> prefix(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i)
                prefix[i] = a[i] + prefix[i - 1];
            else
                prefix[i] = a[i];
        }
        if (s >= prefix[n - 1]) {
            cout << 0 << endl; continue;
        }
        //print(prefix);
        int rem = 0, mx = 0;
        int x = upper_bound(all(prefix), s) - prefix.begin();
        if (x == n)
            x--;


        for (int i = 0; i <= x; i++) {
            //removeing ith gift
            //instead making new prefix array all the time we can simply search for s+a[i] as 
            //we have to remove a[i] from all the other which is costly process
            int pos = lower_bound(all(prefix), s + a[i]) - prefix.begin();
            if (pos == n)
                pos--;
            if (prefix[pos] > s + a[i])
                pos--;
            if (mx < pos) {
                mx = pos;
                rem = i + 1;
            }
        }
        cout << rem << endl;
    }
    return 0;
}