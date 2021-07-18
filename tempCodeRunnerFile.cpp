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

bool check(int a, int b) {
   float k = log(a) / log(b);
   if (ceil(k) == floor(k))
      return true;
   else
      return false;
}
int main()
{
   FIO;
   int t;
   cin >> t;
   while (t--) {
      int n, a, b; cin >> n >> a >> b;
      int i = 0;
      int val = 0;
      bool flag = 0;
      while (val <= n) {
         val = n - (i * b);
         if (check(val, 3)) {
            flag = 1; break;
         }
         i++;
      }
      if (flag)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
   return 0;
}