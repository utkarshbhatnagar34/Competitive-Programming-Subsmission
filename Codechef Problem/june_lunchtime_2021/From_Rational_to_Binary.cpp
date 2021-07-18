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
      ll a, b; cin >> a >> b;
      if (b % 2 == 0) {
         if (ceil(log2(b)) == floor(log2(b)))
            cout << "Yes" << endl;
         else
            cout << "No" << endl;
      }
      else
         cout << "No" << endl;
   }
   return 0;
}