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
#define mod 1000000007

int main()
{

  FIO;
  int n;
  cin >> n;
  int a[n];
  ll s = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    s = (s + a[i]) % mod;
    if (s < 0)
      s += mod;
  }
  int q;
  cin >> q;
  int x;
  for (int i = 0; i < q; i++)
  {
    cin >> x;
    s = (s * 2) % mod;
    if (s < 0)
      s += mod;

    cout << s << endl;
  }
  return 0;
}