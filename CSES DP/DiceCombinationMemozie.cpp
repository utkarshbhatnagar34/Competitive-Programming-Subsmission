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
#define mod           1000000007
int dp[1000001];
int solve(int target) {
	if (target < 0) return 0;
	if (target == 0)  return 1;
	if (dp[target] != -1) return dp[target];

	ll sum = 0;
	for (int i = 1; i <= 6 && i <= target; i++)
		sum = (sum + solve(target - i)) % mod;

	return dp[target] = sum;
}
int main()
{
	FIO;
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n);
	return 0;
}