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

    int r, b, d;
    cin >> r >> b >> d;
    int c1 = min(r, b);
    int c2 = max(r, b);
    r = c1, b = c2;
    //either r<b  or r==b
    //if r==b than difference is minimum 0 so always true
    if (r == b)
      cout << "YES";
    else
    {

      if (b > (ll)(r * 1ll * (d + 1)))
      {
        cout << "NO";
      }
      else
        cout << "YES";
    }
    cout << endl;
  }
  return 0;
}
/*so r<b
maximum b we can use when
we put 1 red bean in each bag(maximum r bag are possible)
and d+1 blue bean in each bag
1 d+1
. ..
. ..
1 d+1(r times)
if after it blue beans are left than it cannot be utilised or cannot be distributed
*/
