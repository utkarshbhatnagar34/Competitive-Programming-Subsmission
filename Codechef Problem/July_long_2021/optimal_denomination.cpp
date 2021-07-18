#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define  endl    "\n"
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

//refer to this
//https://www.geeksforgeeks.org/queries-gcd-numbers-array-except-elements-given-range/
int main()
{
  FIO;
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    if (n == 1) {
      cout << 1 << endl; continue;
    }
    else if (n == 2) {
      cout << 2 << endl; continue;
    }

    sort(a, a + n);

    vector<int> prefix(n), suffix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = __gcd(prefix[i - 1], a[i]);
    }

    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = __gcd(suffix[i + 1], a[i]);
    }

    //not taking the first number
    int mx = suffix[1];
    int idx = 0;

    for (int i = 2; i < n; i++) {
      int hcf = __gcd(prefix[i - 2], suffix[i]);
      if (hcf > mx) {
        idx = i - 1;
        mx = hcf;
      }
    }

    //not taking the last number
    if (mx < prefix[n - 2]) {
      mx = prefix[n - 2];
      idx = n - 1;
    }


    if (mx == 1 || mx == prefix[n - 1]) {
      ll ans = 1;
      for (int i = 0; i < n - 1; i++)
        ans += a[i] / mx;
      cout << ans << endl;
      continue;
    }


    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (i == idx) {
        ans++;
      }
      else {
        ans += a[i] / mx;
      }
    }
    cout << ans << endl;
  }
  return 0;
}