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

int power(int a, int b, int mod)
{
  int result = 1;
  while (b > 0)
  {
    if (b % 2 == 1)
      result = ((result)*1LL * (a)) % mod;
    a = ((a)*1ll * (a)) % mod;
    b = b / 2;
  }
  return result;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  FIO;
  int t;
  cin >> t;
  while (t--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    // is p is prime and a,b,c<p so all are co prime/relativly prime to p
    //using fermat little theorm
    int mod = 1000000007;
    int y = power(b, c, mod - 1);
    int ans = power(a, y, mod);
    cout << ans << endl;
  }
  return 0;
}