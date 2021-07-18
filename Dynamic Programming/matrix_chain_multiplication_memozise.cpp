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
int n;
vector<int> a;
vector<vector<int>> dp;
int min_cost(vector<int> a, int x, int y)
{
  if (x >= y)
    return 0;

  if (abs(x - y) == 1)
  {
    return a[x - 1] * a[x] * a[y];
  }
  if (dp[x][y] != -1)
    return dp[x][y];

  ///// calculating
  int cost = INT_MAX;
  for (int i = x; i < y; i++)
  {
    int temp = min_cost(a, x, i) + min_cost(a, i + 1, y) + a[x - 1] * a[i] * a[y];
    if (temp < cost)
    {
      cost = temp;
    }
  }
  return dp[x][y] = cost;
}
int main()
{
  FIO;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  dp.resize(n + 1);
  for (int i = 0; i <= n; i++)
    dp[i].resize(n, -1);

  cout << min_cost(a, 1, n - 1);
  return 0;
}