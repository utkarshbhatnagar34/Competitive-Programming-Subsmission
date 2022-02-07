#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--) {
      int n;cin>>n;
      int a[n];bool flag=1;
      for(int i=0;i<n;i++){
      cin>>a[i];
      if(i){
        if(a[i-1]!=a[i])
          flag=0;
      }
      }
      if(flag){
        cout<<0<<endl;continue;
      }

      int l=0,r=n-1,step=0,s1=a[l],s2=a[r];
      while(l<r){
        if(s1==s2){
          if((r-l)-1){
            if(((r-l)-1)==1){
              if(s1==a[l+1]){
                break;
              }
              else{
                s1=a[l+1];l++;
              }
            }
            else{
              if(s1)
            }
          }
        }
        else if(s1<s2){
          l++;
          if(l<r)
           s1+=a[l];
           step++;
        }
        else{
          r--;
          if(l<r)
          s2+=a[r];
          step++;
        }
      }
      if(s1==s2){
        cout<<step<<endl;
      }
      else{
        cout<<n-1<<endl;
      }
    }
    return 0;
}