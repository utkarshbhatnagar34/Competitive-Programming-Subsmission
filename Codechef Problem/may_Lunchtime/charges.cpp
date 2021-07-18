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
    int n, k;
    cin >> n >> k;
    int a[n];
    string s;
    cin >> s;
    int distance = 0;
    for (int i = 0; i < s.length(); i++)
    {
      a[i] = s[i] - '0';
      if (i)
      {
        if (a[i] == a[i - 1])
          distance += 2;
        else
          distance += 1;
      }
    }
    //cout << distance << endl;
    int pre = 0, cur = 0;
    int change = 0;
    int idx;
    if (n == 1)
    {
      for (int i = 0; i < k; i++)
      {
        int ii;
        cin >> ii;
        cout << distance << endl;
      }
    }
    else
    {
      for (int i = 0; i < k; i++)
      {
        cin >> idx;
        idx--;
        //cout << " " << idx << endl;
        if (idx == 0)
        {
          if (a[idx] == a[idx + 1])
            distance -= 1;
          else
            distance += 1;
        }
        else if (idx == n - 1)
        {
          if (a[idx] == a[idx - 1])
            distance -= 1;
          else
            distance += 1;
        }
        else
        {
          //right
          if (a[idx] == a[idx + 1])
            distance -= 1;
          else
            distance += 1;
          //left
          if (a[idx] == a[idx - 1])
            distance -= 1;
          else
            distance += 1;
        }
        if (a[idx] == 1)
          a[idx] = 0;
        else
          a[idx] = 1;
        cout << distance << endl;
      }
    }
    //cout << distance << endl;
  }
  return 0;
}