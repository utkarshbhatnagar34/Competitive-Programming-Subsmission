#include<bits/stdc++.h>
using namespace std;
const int mod = 1e7 + 9;
/*
  a[]=2 3 5 target=7
the difference between Coin Combination/change 1 and Coin Combination 2 is that 2+2+3 and 2+3+2 are considered 
same in Coin Combination 2 but different in 1 ,but how
but have different (its what we use in 1 to differ in both of them)prefix sum by which they are differ 2+2=4 and 2+3=6 on next step they became equal  
So recurrence relation is solve(a,i,target-a[i]) we always start with 0 in for(--) loop

To avoid it we simply start from i in every for(--) loop
Means after taking 2's it can only have option to take 3 or 5
Similarly after taking 3's it can take only 5
So we use 2D dp[index][target] to optimize it we have to use iterative dp

And to prefrom the same thing in iterative manner for every amount i we give a[j] to it in this way we avoid 
*/
int dp[101][1000001];
int solve(vector<int> &a, int idx, int target) {
  int n = a.size();
  if (target < 0) return 0;
  if (target == 0) {
    return 1;
  }
  if (dp[idx][target] != -1) return dp[idx][target];

  int ans = 0;
  for (int i = idx; i < n; i++) {
    ans = solve(a, i, target - a[i]) + ans;
  }
  return dp[idx][target] = ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  cout << solve(a, 0, x);
}