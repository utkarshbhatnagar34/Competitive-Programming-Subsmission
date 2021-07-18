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
    int n;
    cin >> n;
    int a;
    vector<int> neg, pos;
    int zr = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      if (a == 0)
        zr++;
      if (a <= 0)
        neg.push_back(abs(a));
      else if (a > 0)
        pos.push_back(a);
    }
    if (n == 1)
    {
      cout << 1 << endl;
      continue;
    }
    //difference bada ho nhi skata 2 positive elements ke beech jaab tak ek koi negative na ho
    if (neg.size() == n)
    {
      cout << n << endl;
      continue;
    }
    else if (pos.size() + zr == n)
    {
      if (zr > 1)
        cout << zr << endl;
      else if (zr == 1)
        cout << 2 << endl;
      else
        cout << 1 << endl;
      continue;
    }
    vector<int> diff;
    int nn = neg.size();
    //sorting both them is nessesary(not sorting neg cost me 6 submissions)
    //after sortin neg we can found minimum difference possible
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    for (int i = 1; i < nn; i++)
    {
      diff.push_back(abs(neg[i] - neg[i - 1]));
    }
    sort(diff.begin(), diff.end());
    int ans = nn;
    /*if there are more than one zero than their can be any positive elements in the array
          if there is only one zero than if min_difference >=positive number than only in array*/
    if (nn == 1)
    {
      if (zr > 1)
        cout << ans << endl;
      else if (zr)
      {
        if (pos.size())
          ans += (neg[0] >= pos[0]) ? 1 : 0;
        cout << ans << endl;
      }
      else
      {
        if (pos.size())
          ans += 1;
        cout << ans << endl;
      }
    }
    else
    {
      if (zr > 1)
        cout << ans << endl;
      else if (zr)
      {
        if (pos.size())
          ans += (diff[0] >= pos[0]) ? 1 : 0;
        cout << ans << endl;
      }
      else
      {
        if (pos.size())
          ans += (diff[0] >= pos[0]) ? 1 : 0;
        cout << ans << endl;
      }
    }
  }
  return 0;
}