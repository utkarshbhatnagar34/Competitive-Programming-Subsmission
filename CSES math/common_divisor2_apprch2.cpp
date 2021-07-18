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

int main()
{

  FIO;
  int n;
  cin >> n;
  int a[n];
  int kk = 1e6 + 1;
  int factor[kk] = {0};
  factor[1] = 2;

  /*in this approach we input number than find all its factors(by increasing factor[j]
   and input 2nd number and find all its factor and store it(by increasing factor[j])

   as we perform hcf in school we write down factor which occur in both we do same here

   we loop from 1e6 to 1 and see if there is a number who is factor of 2 or more number
    */

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];

    for (int j = 1; j * 1ll * j <= a[i]; j++)
    {
      if (a[i] % j == 0)
      {
        factor[j]++;

        if (j != (a[i] / j))
        {
          factor[a[i] / j]++;
        }
      }
    }
  }
  int ans = 1;
  for (int i = kk; i >= 1; i--)
  {
    if (factor[i] > 1)
    {
      ans = i;
      break;
    }
  }
  cout << ans;
  /*ex: 36=2*2*3*3
         48=2*2*2*2*3
         hcf(common factor)=2*2*3=12
         so when we factor[36/3=12]++;
         and
         factor[48/4=12]++
   */
  return 0;
}