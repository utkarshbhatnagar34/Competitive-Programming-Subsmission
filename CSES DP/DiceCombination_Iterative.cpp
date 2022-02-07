#include <bits/stdc++.h>
using namespace std;

#define  endl           "\n"
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
#define mod           1000000007

int main()
{
	FIO;
	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6 && i >= j; j++) {
			dp[i] = (dp[i] + 0ll + dp[i - j]) % mod;
		}
	}
	cout << dp[n];
	return 0;
}