#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
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
      int a[n];
      int od = 0, ev = 0;
      std::vector<int> v1, v2;

      for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (a[i] % 2 == 0) {
            v1.push_back(a[i]);
         }
         else
            v2.push_back(a[i]);
      }

      od = v2.size();
      ev = v1.size();
      if (ev >= od) {
         int x = 0, y = 0;
         while (x < ev) {
            cout << v1[x] << " "; x++;
         }
         while (y < od) {
            cout << v2[y] << " "; y++;
         }
      }
      else {
         int x = 0, y = 0;
         int i = 0;
         while (x < ev) {
            cout << v1[x] << " "; x++;
         }

         while (y < od) {
            cout << v2[y] << " "; y++;
         }
      }
      cout << endl;
   }
   return 0;
}