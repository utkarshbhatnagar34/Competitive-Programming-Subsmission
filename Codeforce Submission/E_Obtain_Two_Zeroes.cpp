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
bool check(ll a,ll b,ll x,ll x2){
  ll m=a-x,n=b-x2;
  if(m>n) swap(m,n);
  ll hcf=__gcd(m,n);
  if(m<0||n<0) return false;
  if(m/hcf==1&&n/hcf==2)
   return true;
  return false;
}
int main()
{
  FIO;
  int test;
  cin >> test;
  while (test--)
  {
    ll a, b;
    cin >> a >> b;
    if(a>b) swap(a,b);
    if ((a + 0ll + b) % 3 != 0)
    {
      cout << "NO" << endl;
      continue;
    }
    ll sum = a + 0ll + b;
    ll x = sum / 3;
    ll x2 = x * 2;
    // cout<<a<<" "<<b<<" "<<x<<" "<<x2<<endl;
    if (a == x && b == x2)
      cout << "YES" << endl;
    else if(a>x||b>x2){
      bool flag=0;
      ll l=1,r=x,mid;
      while(l<=r){
        mid=l+(r-l)/2;
        if(check(a,b,mid,mid*2)){
          flag=1;break;
        }
        else if(a-mid>1){
          l=mid+1;
        }
        else
        r=mid-1;
      }
      if(flag)
      cout<<"YES"<<endl;
      else
      cout<<"NO"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}