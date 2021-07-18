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
#define mod    1000000007
ll find_lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

int main()
{
  FIO;
  int t;
  cin >> t;
  ll lcm = 1;
  vector<ll> v;
  for (int i = 2; i <= 41; i++) {
    lcm = find_lcm(lcm, i);
    v.push_back(lcm);
  }
  while (t--) {
    ll n; cin >> n;
    if (n == 1) {
      cout << 2 << endl; continue;
    }
    if (n == 2) {
      cout << 5 << endl; continue;
    }
    if (n == 3) {
      cout << 7 << endl; continue;
    }
    ll ans = 0;
    //for long long numbers ceil((float)n/2) doesnt work properly use it 
    if (n % 2 == 0)
      ans = n;
    else
      ans = n + 1;

    //now odd numbers remains only
    ll pp = 0;//it contain numbers which is previously counted before the present number
    for (int i = 39; i >= 0; i--) {
      ll k = n / v[i];
      k -= pp;
      ans += k * (i + 3);
      pp += k;
      // cout << k << " " << v[i] << " " << i + 3 << endl;
    }
    cout << ans % mod << endl;
  }
  return 0;
}