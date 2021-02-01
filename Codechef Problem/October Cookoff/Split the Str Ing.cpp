#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());

inline bool check(string s, char ch, int ii, int n) {
  //cout << ii << " " << n << endl;
  for (int i = ii; i <= n; i++) {
    //cout << s.substr(i, 2) << endl;
    if (ch == (s[i]))
    {
      return true;
    }
  }
  return false;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  FIO;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool back = false;
    char bk_str;
    bk_str = s[n - 1];
    //cout << fr_str << " " << bk_str << endl;
    back = check(s, bk_str, 0, n - 2);
    //cout << back << endl;
    if (back)
      cout << "YES";
    else
      cout << "NO";

    cout << endl;
  }
  return 0;
}