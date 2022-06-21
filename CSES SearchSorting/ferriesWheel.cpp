#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
 
#define  endl           "\n"
#define  all(v)         (v).begin(),(v).end()
#define  sz(v)          (int)(v).size()
#define  getunique(v)   {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  print(v)       {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
//#define mod           1000000007
 
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  FIO;
  ll n, x;
  cin >> n >> x;
 
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(all(arr));
  int l = 0, r = n - 1, ans = 0;
 
  while (l <= r) {
    if (arr[l] + arr[r] <= x) {
      l++; r--; ans++;
    }
    else {
      ans++; r--;
    }
  }
  cout << ans << endl;
  return 0;
}