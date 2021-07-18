#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
      cin >> h[i];
    //(height,index)
    set<pii> s;
    for (int i = 0; i < m; i++)
    {
      s.insert({0, i});
    }
    vector<int> place(n);
    for (int i = 0; i < n; i++)
    {
      auto it = s.begin();
      int hei = it->first;
      int idx = it->second;
      hei += h[i];
      place[i] = idx + 1;
      s.erase(it);
      s.insert({hei, idx});
    }
    auto it1 = s.begin();
    auto it2 = s.end();
    it2--;
    if ((it2->first) - (it1->first) <= x)
    {
      cout << "YES\n";
      // for (auto i : s)
      // 	cout << i.first << " ";
      // cout << endl;
      for (auto i : place)
        cout << i << " ";
    }
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}