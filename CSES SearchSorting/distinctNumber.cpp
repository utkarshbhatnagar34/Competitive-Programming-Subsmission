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
  FIO;
  int n; cin >> n;
  set<int> st;
 
  for (int i = 0; i < n; i++) {
    int a; cin >> a; st.insert(a);
  }
 
  cout << st.size() << endl;
  return 0;
}