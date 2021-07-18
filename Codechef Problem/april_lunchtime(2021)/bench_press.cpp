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

    int n, w, rod;
    cin >> n >> w >> rod;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    if (w <= rod)
      cout << "YES";
    else
    {
      int req = w - rod;

      ll total = 0;
      sort(a, a + n, greater<int>());

      vector<int> v;
      for (int i = 1; i < n; i++)
      {
        if (a[i] == a[i - 1])
        {
          v.push_back(a[i]);

          i++;
        }
      }
      int len = v.size();
      for (int i = 0; i < len; i++)
      {
        if (total < req)
        {
          total += (2 * v[i]);
        }
      }

      if (total >= req)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << endl;
  }
  return 0;
}