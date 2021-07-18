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
  ll n;
  cin >> n;
  ll a, b;
  if (n == 1)
  {
    cout << n << " " << n << endl;
    return 0;
  }
  //finding factors
  ll minel = INT_MAX;
  for (ll i = 1; (i * i) <= n; i++)
  {
    if (n % i == 0)
    {
      if (i != n / i)
      {
        if (minel > max(i, n / i))
        {
          minel = max(i, n / i);
          a = i, b = n / i;
        }
      }
    }
  }
  //a*b=lcm(a,b)*gcd(a,b) to equation to hold true in above case gcd(a,b)==1
  if (__gcd(a, b) == 1)
  {
    cout << a << " " << b << endl;
  }
  else
  {
    ;
  }
  return 0;
}