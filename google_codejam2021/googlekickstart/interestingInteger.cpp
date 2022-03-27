#include <bits/stdc++.h>
using namespace std;

typedef    long long ll;
typedef    long double lld;
typedef    unsigned long long ull;
typedef    pair<int, int> pii;

#define    all(v) (v).begin(),(v).end()
#define    sz(v) (int)(v).size()
#define    getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define    print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define    endl    "\n"
#define    SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
//const    lld pi = 3.14159265358979323846;
//#define  mod    1000000007
bool valid(ll num){
  string s=to_string(num);
  ll pro=1,sum=0;
  for(int i=0;i<s.size();i++){
    int d=s[i]-'0';
    sum+=d;
    pro*=d;
  }
  return (pro%sum)==0;
}
int main()
{
  SPEED;
  int t;
  int test = 0;
  cin >> t;
  while (t--) {
    test++;
    cout << "Case #" << test << ": ";
    ll a,b;cin>>a>>b;
    ll num=a,ans=0;
    while(num<=b){
      if(valid(num)){
        ans++;
      }
      num++;
    }
    cout<<ans<<endl;
  }
  return 0;
}

