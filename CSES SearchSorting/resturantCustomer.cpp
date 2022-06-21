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

bool comp(pair<int,int> &a,pair<int,int> &b){
  return a.second<b.second;
}
int main()
{
  FIO;
  int n;cin>>n;
  vector<pair<int,int> > v(n);
  for(int i=0; i<n; i++){
    int a,b;cin>>a>>b;
    v[i].first = a; v[i].second = b;
  }
  sort(all(v),comp);
  int ans=0,together=1;
  
  int end=v[0].second;
  for(int i=1;i<n;i++){
    if(v[i].first>=end){
      together++;ans=max(ans,together);
      end=max(end,v[i].second);
    }
  }
  return 0;
}