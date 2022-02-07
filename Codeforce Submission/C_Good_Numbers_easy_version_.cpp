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
bool check(int n) {
    while (n > 0) {
        if (n % 3 > 1)
            return false;
        n = n / 3;
    }
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
  //  freopen("input.in", "r", stdin);
  //  freopen("output.in", "w", stdout);
#endif
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        while (check(n) == false) {
            n++;
        }
        cout << n << endl;
    }
    return 0;
}