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
ll find_hcf(ll diff[], ll n)
{
  ll hcf = diff[0];
  for (ll i = 1; i < n; i++)
  {
    hcf = __gcd(hcf, diff[i]);
  }
  return hcf;
}
int main()
{
  FIO;
  ll n, m;
  cin >> n >> m;
  ll x[n], p[m];
  ll diff[n - 1];
  ll hcf = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> x[i];
    if (i)
    {
      diff[i - 1] = x[i] - x[i - 1];
    }
  }
  ll a[m];
  for (ll i = 0; i < m; i++)
  {
    cin >> p[i];
    a[i] = p[i];
  }
  hcf = find_hcf(diff, n - 1);
  
  int i=0;
  bool flag=0;
  //cout<<hcf<<endl;
  for(i=0;i<m;i++){
    if(hcf>=p[i]&&hcf%p[i]==0){
      flag=1;break;
    }
  }
  if(flag){
    cout<<"YES"<<endl;
    cout<<x[0]<<" "<<i+1<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}