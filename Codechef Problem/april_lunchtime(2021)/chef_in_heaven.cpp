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
    int l;
    cin >> l;
    string s;
    cin >> s;
    int gud = 0, bad = 0, prec = 0;
    bool flag = 0;
    for (int i = 0; i < l; i++)
    {
      if (s[i] == '0')
        bad++;
      else
        gud++;

      prec = (gud * 100) / (i + 1);
      //cout << prec / (i + 1) << endl;

      if (prec >= 50)
      {
        flag = 1;
        break;
      }
    }

    if (flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}