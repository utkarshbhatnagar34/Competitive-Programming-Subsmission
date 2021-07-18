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

//codeforces round 549 B
int digit_multi(int n)
{
  int mul = 1;
  while (n > 0)
  {
    int d = n % 10;
    mul = mul * d;
    n /= 10;
  }
  return mul;
}

int main()
{
  FIO;
  int n;
  cin >> n;
  if (n <= 9)
  {
    cout << n << endl;
    return 0;
  }
  string sn = to_string(n);
  int len = sn.length();

  string num = sn;
  int ans = digit_multi(n);
  for (int i = len - 1; i >= 0; i--)
  {
    sn[i] = '9';
    num = sn;
    if (i == 0)
    {
      num[i] = '0';
    }
    else
    {
      int j = i - 1;
      while (j >= 0 && num[j] == '0')
      {
        num[j] = '9';
        j--;
      }
      int kk = num[j] - '0';
      kk--;
      num[j] = char(kk + '0');
    }
    int n2 = stoi(num);
    ans = max(ans, digit_multi(n2));
  }
  cout << ans;
  return 0;
}