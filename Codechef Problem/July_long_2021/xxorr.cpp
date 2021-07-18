#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int main()
{
  FIO;
  int t;
  cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int bit[32] = {0};
    int bc = (1 << 30);
    //cout << bc << endl;
    for (int i = 0; i < 31; i++) {
      int num = 1 << i;
      for (int j = 0; j < n; j++) {
        if (num & a[j]) {
          bit[i]++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < 31; i++) {
      //cout << bit[i] << " ";
      if (bit[i] > 0 && bit[i] <= k) {
        ans += 1;
      }
      else {
        ans += bit[i] / k;
        if (bit[i] % k != 0)
          ans += 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}