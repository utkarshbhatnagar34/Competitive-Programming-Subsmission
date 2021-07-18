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
    ll x, y;
    cin >> x >> y;
    if (y < x || y % x != 0)
    {
      cout << -1 << endl;
      continue;
    }
    ll sum = 0, pre_s = 0;
    ll time = 0;
    map<int, int> m;
    bool flag = 0;
    while (true)
    {
      ll sum = pre_s, i = 1;
      ll add = 0;
      while (sum < y)
      {
        time++;
        pre_s = sum;
        sum += x * 1ll * i;
        add++;
        i = i * 1ll * 2;
      }
      if (sum != y && m[add - 1] != 0)
      {
        break;
      }
      else if (sum == y && m[add] != 0)
      {
        break;
      }
      if (sum != y)
        m[add - 1]++;

      if (pre_s == y || sum == y)
      {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << time << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}