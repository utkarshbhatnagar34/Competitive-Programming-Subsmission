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
    string s;
    cin >> s;
    int len = s.length();
    string ns, k;
    if (s[0] == '1')
    {
      k = s.substr(1, len - 1);
      ns = s[0];
      ns.push_back('0');
      ns = ns + k;
    }
    else
    {
      ns = '1' + s;
    }
    cout << ns << endl;
  }
  return 0;
}