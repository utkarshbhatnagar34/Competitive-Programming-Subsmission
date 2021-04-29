#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define endl "\n"
#define FIO                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

int main()
{

  FIO;
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;
    int hcf = __gcd(a, b);
    if (hcf == 1)
    {
      ll ans = (a * 1ll * b) - a - b;
      cout << ans + 1 << endl;
    }
    else
      cout << -1 << endl;
  }
  return 0;
}