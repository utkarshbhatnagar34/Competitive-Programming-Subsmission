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

ll nc2(ll n)
{
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
    ll N, M;
    cin >> N >> M;
    ll oder_par = N - 1; //1 can make pair with everyone
    //whenN<=M
    //cout << oder_par << endl;
    vector<int> remainder = {0, 0};

    for (int i = 2; i <= min(M / 2, N); i++)
    {
      remainder.push_back(M % i);
    }

    for (int i = 2; i < remainder.size(); i++)
    {
      int rem = remainder[i];
      //cout << i << endl;
      for (int j = i + 1; j < remainder.size(); j++)
      {
        //cout << j << " " << remainder[j] << endl;
        if (rem == remainder[j] % i)
        {
          oder_par++;
          //cout << i << " " << j << endl;
        }
      }
      if (N > M / 2)
      {
        oder_par += (N / i) - ((M / 2) / i);
      }
    } //cout << oder_par << endl;

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