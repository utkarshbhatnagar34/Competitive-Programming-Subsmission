#include <bits/stdc++.h>
using namespace std;

#define    endl    "\n"
#define    SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
int mxn = 1e5;
int main()
{
  SPEED;
  int a, b; cin >> a >> b;
  if (a < b) swap(a, b);

  int dp[a + 1][b + 1];
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      dp[i][j] = mxn;

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (i == j) dp[i][j] = 0;
      else {

        for (int k = 1; k < i; k++) {
          dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
        }

        for (int k = 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        }
      }
    }
  }

  cout << dp[a][b] << endl;
  return 0;
}