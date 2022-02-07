#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define getunique(v)                    \
   {                                    \
      sort(all(v));                     \
      v.erase(unique(all(v)), v.end()); \
   }
#define endl "\n"
#define FIO                      \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);                   \
   cout.tie(0)
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
   while (t--)
   {
      int n;
      cin >> n;
      int a = n / 3;
      if (n % 3 == 0)
      {
         cout << a << " " << a << endl;
      }
      else if (n % 3 == 1)
      {
         cout << a + 1 << " " << a << endl;
      }
      else
      {
         cout << a << " " << a + 1 << endl;
      }
   }
   return 0;
}