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
#ifndef ONLINE_JUDGE
  // freopen("input.in", "r", stdin);
  // freopen("output.in", "w", stdout);
#endif
   FIO;
   int t;
   cin >> t;
   while (t--) {
      int n, k; cin >> n >> k;
      int a[n];
      unordered_map<int, vector<int>> mp;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         mp[a[i]].push_back(i);
      }


      int ans[n];
      memset(ans, 0, sizeof(ans));

      vector<int> left;
      int sum = 0;

      for (auto i : mp) {
         //cout << i.first << " " << sz(i.second) << endl;
         if (sz(i.second) >= k) {
            int freq = 1;
            for (int j = 0; j < sz(i.second) && freq <= k; j++) {
               ans[i.second[j]] = freq;
               ++freq;
            }
         }
         else {
            for (auto it : i.second) {
               left.push_back(it);
            }
         }
      }
      if (sz(left) >= k) {
         int ele = (sz(left) / k) * k;
         int freq = 1;
         for (int i = 0; i < ele; i++) {
            ans[left[i]] = freq;
            freq++;
            if (freq > k)
               freq = 1;
         }
      }

      for (int i = 0; i < n; i++) {
         cout << ans[i] << " ";
      }
      cout << endl;
   }
   return 0;
}