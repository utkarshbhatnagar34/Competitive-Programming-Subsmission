#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int main()
{
   FIO;
   int t;
   cin >> t;
   while (t--) {
      int n; cin >> n;
      int l, r; cin >> l >> r;
      int a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];

      sort(a, a + n);

      int mx = 0;
      for (int i = 0; i + 1 < n; i++) {
         
      }
      cout << mx << endl;
   }
   return 0;
}