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
//#define mod    1000000007
//prime seive
//maximum array size 1e8
const int mxn = 1e7 + 7;
int prime[mxn];
std::vector<int> v;
int idx;
int ans[mxn];
int no_pr = 0;
void seive()
{
  memset(prime, 0, sizeof(prime));
  prime[0] = -1;
  prime[1] = -1;
  for (int i = 2; i <= mxn; i++)
  {
    if (prime[i] == 0)
    {
      //v.push_back(i);
      no_pr += 1;
      for (int j = 2; j * i <= mxn; j++)
      {
        prime[j * i] = -1;
      }
    }
    //if number is not prime than it will some multiple 2*prime
    if (prime[i] == -1)
    {
      //i=2*prime than i must be included in set 2
      //we have not to check for 3,4,5.. multiple of prime as they are included already
      if (i % 2 == 0)
      {
        if (prime[i / 2] == 0)
        {
          no_pr--;
        }
      }
    }
    ans[i] = no_pr;
    //total_pr[i] = no_pr;
  }
}

int main()
{
  FIO;
  int t;
  cin >> t;
  seive();
  while (t--)
  {
    int n;
    cin >> n;
    if (n == 2)
    {
      cout << 1 << endl;
      continue;
    }
    else if (n == 3)
    {
      cout << 2 << endl;
      continue;
    }
    else
    {
      cout << ans[n] + 1 << endl;
    }
  }
  return 0;
}