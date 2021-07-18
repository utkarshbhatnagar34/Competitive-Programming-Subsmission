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
    int x;
    cin >> x;
    int i = 1;
    bool flag = false;
    int ans = 0, sum = 0, ss;
    while (true)
    {
      sum = ((i * (i + 1)) / 2);
      if (x == sum)
      {
        ans = i;
        flag = 1;
        break;
      }
      //cout<<i<<" "<<sum<<endl;
      for (int j = 1; j <= i && i != 1; j++)
      {
        ss = sum - 1 - j;
        //cout<<ss<<endl;
        if (ss == x)
        {
          ans = i;
          flag = true;
          break;
        }
      }
      if (flag)
        break;
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}