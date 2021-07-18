#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define endl "\n"
#define FIO                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009
int sum_digit(int n)
{
  int sum = 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main()
{
  FIO;
  ll n;
  cin >> n;
  vector<int> ans;
  //atmost sum of digit(x) of num from 1->10^9 is 100 just iterating over it
  //and checking if n-x=k if sum of digit of k==x
  int c = 0;
  for (int i = 1; i <= 100; i++)
  {
    int k = n - i;
    if (sum_digit(k) == i)
    {
      c++;
      ans.push_back(k);
    }
  }
  if (c)
  {
    cout << c << endl;
    sort(ans.begin(), ans.end());
    for (auto i : ans)
      cout << i << endl;
  }
  else
    cout << 0 << endl;
  return 0;
}