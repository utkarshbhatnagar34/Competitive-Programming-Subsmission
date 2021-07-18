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
//#define mod    1000000007

int main()
{
  FIO;
  int t;
  cin >> t;
  while (t--)
  {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll k11 = (x1 * 1ll * (x1 + 1)) / 2;
    ll ori_x1 = x1;
    for (ll i = 2; i <= y1; i++)
    {
      k11 += x1;
      x1++;
    }
    ll ad2 = x1;
    //cout << k11 << " " << ad2 << endl;
    ll sum = 0;
    ll xn;
    for (ll i = ori_x1; i <= x2; i++)
    {
      sum += k11;
      ad2++;
      //cout << k11 << " " << ad2 << endl;
      k11 += ad2;
    }
    k11 = k11 - ad2;
    ad2--;
    //cout << k11 << " " << ad2 << endl;
    for (ll i = y1 + 1; i <= y2; i++)
    {
      sum += k11 + ad2;
      //cout << k11 + ad2 << endl;
      k11 = k11 + ad2;
      ad2++;
    }
    cout << sum << endl;
  }
  return 0;
}