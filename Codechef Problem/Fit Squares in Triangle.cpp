#include <bits/stdc++.h>
using namespace std;
#define ll       long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
// look closely 1 3 6 10 its AP(miscellaneous series)
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
    int b;
    cin >> b;
    if (b == 1 || b == 2 || b == 3)
      cout << 0;
    else {
      if (b & 1)
        b--;
      b /= 2;
      b--;
      cout << ((b) * (b + 1)) / 2;
    }
    cout << endl;
  }
  return 0;
}
