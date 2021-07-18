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
    int n;
    cin >> n;
    vector<int> u(n);
    //university
    for (int i = 0; i < n; i++)
    {
      cin >> u[i];
      //cout << u[i] << endl;
    }

    vector<vector<ll>> skill(n + 1);
    int sk;
    //skill for ith student
    for (int i = 0; i < n; i++)
    {
      cin >> sk;
      skill[u[i]].push_back(sk);
    }
    //to use unique function array must be sorted and unique function return the iterator to the last element not resize the array
    sort(u.begin(), u.end());
    auto ip = unique(u.begin(), u.end());
    u.resize(distance(u.begin(), ip));

    //sort decening order
    for (auto it : u)
    {
      sort(skill[it].begin(), skill[it].end(), greater<int>());
      int len = skill[it].size();
    }
    //prefix sum
    for (auto it : u)
    {
      for (int j = 1; j < skill[it].size(); j++)
      {
        skill[it][j] += skill[it][j - 1];
      }
    }

    ll ans[n] = {0};
    //
    for (int i = 1; i <= n; i++)
    {
      int ele = skill[i].size();
      //maximum size of team is maximum number of student in the nth university(optimization)
      for (int k = 1; k <= ele; k++)
      {
        ans[k - 1] += skill[i][((ele / k) * k) - 1];
      }
    }
    for (auto i : ans)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}