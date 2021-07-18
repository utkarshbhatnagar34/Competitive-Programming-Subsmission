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
  int n, m, k;
  cin >> n >> k >> m;
  int a[n];
  map<int, int> mp;
  vector<vector<int>> v(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mp[(a[i] % m)]++;
    v[a[i] % m].push_back(a[i]);
  }
  bool flag = 0;
  int rem;
  for (auto i : mp)
  {
    if (i.second >= k)
    {
      flag = 1;
      rem = i.first;
      break;
    }
  }

  if (flag)
  {
    cout << "Yes" << endl;
    for (int i = 0; (i < v[rem].size()) && (i < k); i++)
    {
      cout << v[rem][i] << " ";
    }
  }
  else
    cout << "No";
  return 0;
}