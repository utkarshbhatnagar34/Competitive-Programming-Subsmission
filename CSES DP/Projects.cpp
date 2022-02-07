#include<bits/stdc++.h>
using namespace std;

struct Job
{
  long long start, end, profit;
};

bool comparator(Job &a, Job &b) {
  return a.start <= b.start;
}

long long n;
long long dp[200001];

long long solve(vector<Job> &a, long long idx, vector<long long> &startTime) {
  if (idx == n) return 0;
  if (dp[idx] != -1) return dp[idx];
  
  long long op1 = 0, op2 = 0;
  long long next = upper_bound(startTime.begin(), startTime.end(), a[idx].end) - startTime.begin();

  op1 = a[idx].profit + solve(a, next, startTime);
  op2 = solve(a, idx + 1, startTime);

  return dp[idx] = max(op1, op2);
}

int main() {
  cin >> n;

  vector<Job> a(n);
  vector<long long> startTime(n);

  for (long long i = 0; i < n; i++) {
    cin >> a[i].start >> a[i].end >> a[i].profit;
    startTime[i] = a[i].start;
  }

  sort(a.begin(), a.end(), comparator);
  sort(startTime.begin(), startTime.end());

  memset(dp, -1, sizeof(dp));
  cout << solve(a, 0, startTime);
}