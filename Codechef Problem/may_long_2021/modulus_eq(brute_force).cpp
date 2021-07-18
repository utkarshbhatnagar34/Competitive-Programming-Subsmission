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

ll nc2(int n)
{
  if (n == 1 || n == 0)
    return 0;
  ll ans = (n * 1ll * (n - 1)) / 2;
  return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  FIO;
  int T;
  cin >> T;
  while (T--)
  {
    int N, M;
    cin >> N >> M;
    ll oder_par = N - 1; //1 can make pair with everyone
    //cout << oder_par << endl;
    //whenN<=M
    for (int i = 2; i <= min(M, N); i++)
    {
      for (int j = i + 1; j <= min(M, N); j++)
      {
        if (((M % i) % j) == ((M % j) % i))
        {
          //cout << i << " " << j << endl;
          oder_par++;
        }
      }
    }
    //cout << oder_par << endl;
    //When N>M
    if (N > M)
    {
      ll greater = N - M;
      oder_par += nc2(greater);
      if (M != 1)
      {
        oder_par += greater * (M - 1);
      }
    }
    cout << oder_par << endl;
  }
  return 0;
}