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
#define print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("input.in", "r", stdin);
//   freopen("output.in", "w", stdout);
// #endif
  FIO;
  int n;
  cin >> n;
  ll a[n];
  ll mx = 0;
  unordered_set<ll> st;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    mx = max(mx, a[i]);
    st.insert(a[i]);
  }
  if (st.size() <= 2)
  {
    if (st.size() == 1)
      cout << 0 << " " << 0 << endl;
    else
    {
      ll taken = 0;
      for (int i = 0; i < n; ++i)
      {
        if (a[i] == mx)
          continue;
        taken += mx - a[i];
      }
      cout << 1 << " " << taken << endl;
    }
    return 0;
  }
  ll hcf = mx - a[0]; ll sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += a[i];
    if (a[i] == mx)
      continue;
    hcf = __gcd(hcf, a[i]);
  }

  if (hcf != 0)
    cout << ((mx * n) - sum) / hcf << " " << hcf << endl;
  else
    cout << 0 << " " << 0 << endl;
  return 0;
}