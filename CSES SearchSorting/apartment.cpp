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
  int n, m, k; cin >> n >> m >> k;
 
  vector<int> arr(n), brr(m);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
 
  for (int i = 0; i < m; i++)
    cin >> brr[i];
 
  sort(all(arr)); sort(all(brr));
 
  int l = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    //cout << l << endl;
    int idx = lower_bound(brr.begin() + l, brr.end(), arr[i] - k) - brr.begin();
    // cout << arr[i] - k << " " << idx << " " << brr[idx] << endl;
 
    if (idx < m && brr[idx] <= arr[i] + k) {
      //  cout << arr[i] << endl;
      ans++, l = idx + 1;
    }
  }
  cout << ans << endl;
  return 0;
}