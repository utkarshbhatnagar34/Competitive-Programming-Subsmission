#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  FIO;
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    string str; int b;
    map<string, int> m_pos;
    map<string, int> m_neg;
    unordered_set<string> s;
    for (int i = 0; i < n; i++) {
      cin >> str >> b;
      s.insert(str);
      if (b == 1) {
        m_pos[str]++;
      }
      else {
        m_neg[str]++;
      }
    }
    int taken = 0;
    for (auto it : s) {
      if (m_pos[it] >= m_neg[it]) {
        taken += m_pos[it];
      }
      else {
        taken += m_neg[it];
      }
    }
    cout << taken << endl;
  }
  return 0;
}