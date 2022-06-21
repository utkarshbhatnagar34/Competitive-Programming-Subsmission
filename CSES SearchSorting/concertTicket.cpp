#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define  endl           "\n"
#define  all(v)         (v).begin(),(v).end()
#define  sz(v)          (int)(v).size()
#define  getunique(v)   {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  print(v)       {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
//#define mod           1000000007

int main()
{
  //use multimap
  FIO;
  int n,m;cin>>n>>m;
  vector<int> h(n),t(m);

  for(int i=0;i<n;i++)
    cin>>h[i];

  for(int i=0;i<m;i++)
    cin>>t[i];

  sort(all(h));
  vector<int> ans(m,-1);
  for(int i=0;i<m;i++){
    auto it=lower_bound(h.begin(),h.end(),t[i]);
    int idx=it-h.begin();
    if(idx<n){
      if(h[idx]==t[i]){
        ans[i]=h[idx];
        h.erase(it);
      }
      else if(idx-1>=0){
        ans[i]=h[idx-1];it--;
        h.erase(it);
      }
    }
    else{
      ans[i]=h[idx-1];it--;
      h.erase(it);
    }
  }
  print(ans);
  return 0;
}