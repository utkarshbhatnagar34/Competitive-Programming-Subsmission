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
    int n, x, y;
    cin >> n >> x >> y;
    int k, diff = y - x, extra = abs(n - (diff + 1));
    if (diff + 1 < n)
    {
      if ((x - extra) > 0)
      {
        for (int i = x - extra; i <= y; i++)
          cout << i << " ";
      }
      else
      {
        extra -= x - 1;
        for (int i = 1; i <= y + extra; i++)
          cout << i << " ";
      }
    }
    else if (diff + 1 == n)
    {
      for (int i = x; i <= y; i++)
        cout << i << " ";
    }
    else
    {
      vector<int> ans;
      for (int i = n - 1; i >= 1; i--)
      {
        k = diff / i;
        if (diff % i == 0)
        {
          int strt = y;
          int prit = 1;
          while (strt > 0 && prit <= n)
          {
            ans.push_back(strt);
            strt -= k;
            prit++;
          }
          strt = y + k;
          while (prit <= n)
          {
            ans.push_back(strt);
            strt += k;
            prit++;
          }
          break;
        }
      }
      sort(ans.begin(), ans.end());
      for (auto i : ans)
        cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}