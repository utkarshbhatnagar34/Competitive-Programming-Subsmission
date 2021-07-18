#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007
int solve(int x, int a[], int n, int sum) {
  int q = a[0] * x;
  int r = a[n] / x;
  sum += (q - a[0]) - (a[n] - r);
  return sum;
}
int main()
{
  FIO;
  int n; cin >> n;
  int a[n]; ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  int ans = INT_MAX;
  for (int i = n - 1; i > 0; i--) {
    int n2 = a[i];
    //cout << n2 << endl;
    for (int j = 1; j * 1ll * j <= n2; j++) {
      if (n2 % j == 0) {
        ans = min(ans, solve(j, a, i, sum));
        ans = min(ans, solve(n2 / j, a, i, sum));
      }
    }
  }
  cout << ans;
  return 0;
}