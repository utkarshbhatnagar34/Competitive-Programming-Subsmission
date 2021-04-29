//coin change 3(coins are limited)
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int main() {
	//n->number of coin
	//k-sum
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.in", "w", stdout);
#endif
	int N, K;
	cin >> N >> K;
	int coin[N + 1];
	for ( int i = 1; i <= N; i++ ) {
		cin >> coin[i];
	}
	dp[0][0] = 1;
	for ( int i = 1; i <= N; i++ ) {
		for ( int j = 0; j <= K; j++ ) {
			if ( j == 0 )
				dp[i][j] = 1;
			else if ( j >= coin[i] )
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - coin[i]];
		}
	}

	cout << dp[N][K] << endl;
}