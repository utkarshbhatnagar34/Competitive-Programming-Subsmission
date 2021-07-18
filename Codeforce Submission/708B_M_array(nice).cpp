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
    int n, m;
    cin >> n >> m;
    int a[n];
    ll div = 0, extra = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (a[i] % m != 0)
        mp[(a[i] % m)]++;
      else
      {
        div = 1;
      }
    }

    //2%8=>2 and 6%8=>6 and 2+6=>8 which is divisible by m=8 similarly
    //10%8=>2and 14%8=6 so 10=8+2 and 14=8+6 so 10+14=>(8+2)+(8+6)=>2*8+2+6
    //m=8 (1,7),(2,6),(3,4),(4,4) similar m=odd
    for (int i = 1; i <= m / 2; i++)
    {
      if (m % 2 == 0 && i == m / 2 && mp[m / 2] != 0)
      {
        div++;
      }
      else
      {
        if (mp[i] != 0 && mp[m - i] != 0)
        {
          int mn = min(mp[i], mp[m - i]);
          int mx = max(mp[i], mp[m - i]);
          if (mn != mx)
            extra += mx - (mn + 1);

          div++;
        }
        else
        {
          extra += max(mp[i], mp[m - i]);
        }
      }
    }

    ll ans = div + extra;
    cout << ans << endl;
  }
  return 0;
}