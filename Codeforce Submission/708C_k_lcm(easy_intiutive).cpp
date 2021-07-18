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
void for_n3(int n, int k)
{
  if (n == 3)
  {
    cout << 1 << " " << 1 << " " << 1 << endl;
    return;
  }
  else if (n == 4)
  {
    cout << 1 << " " << 1 << " " << 2 << endl;
    return;
  }
  else if (n == 6)
  {
    cout << 2 << " " << 2 << " " << 2 << endl;
    return;
  }
  //cout << n << "    ";
  int a = n / 2, b, c;
  //cout << a << endl;
  if (n % 2 == 0)
  {
    if (a % 2 == 0)
    {
      cout << a << " " << a / 2 << " " << a / 2 << endl;
    }
    else
    {
      a -= 1;
      cout << a << " " << a << " " << 2 << endl;
    }
  }
  else
  {
    cout << a << " " << a << " " << 1 << endl;
  }
}
int main()
{

  FIO;
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    if (k == 3)
    {
      for_n3(n, k);
      continue;
    }
    int c = 0;
    for (int i = 1; i <= k - 3; i++)
    {
      cout << 1 << " ";
      c++;
    }
    for_n3(n - c, 3);
  }
  return 0;
}