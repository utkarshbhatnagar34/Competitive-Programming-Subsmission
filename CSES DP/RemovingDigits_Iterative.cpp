#include<bits/stdc++.h>
using namespace std;
int inf = 1e6 + 5;
#define print(a){for(auto i:a){cout<<i<<" ";}cout<<endl;}

int main() {
  int n; cin >> n;
  vector<int> dp(n + 1, inf);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int num = i;
    int minstep = 1e6 + 1;
    while (num) {
      int d = num % 10;
      num /= 10;
      if (d == 0) continue;
      dp[i] = min(dp[i], dp[i - d] + 1);//here we use dp[i] as we have already calculated values of dp[i-d] we dont need to do it again
    }
  }
  //print(dp);
  cout << dp[n] << endl;
}