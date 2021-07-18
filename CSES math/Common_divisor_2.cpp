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

/* O(nlogn) approach
  we mark all the number which are given in input arrar in multiple[]
  than we suppose x be the gcd of numbers
  than find all multiple of x
  of multiple of x occur in given input array so we found the number whose gcd will be x

  'gcd of all multiple of x is x'

  visit:
  https://usaco.guide/problems/cses-1081-common-divisors/solution
  and
  https://discuss.codechef.com/t/more-intuitive-explanation-for-the-harmonic-seriess-sum/67287
*/
int main()
{
  FIO;
  int n;
  cin >> n;
  int a;
  int kk = 1e6 + 1;
  int multiple[kk] = {0};

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    multiple[a]++;
  }

  for (int hcf = kk - 1; hcf > 0; hcf--)
  {
    int multiple_found = 0;
    for (int j = hcf; j < kk; j = j + hcf)
    {
      //iterating over all multiple of hcf if it present in input array than increseing it
      multiple_found += multiple[j];
    }
    if (multiple_found > 1)
    {
      cout << hcf;
      break;
    }
  }
  return 0;
}