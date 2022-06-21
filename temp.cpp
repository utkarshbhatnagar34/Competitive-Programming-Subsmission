#include <bits/stdc++.h>
using namespace std;
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
const int mod =1e9 + 7;
typedef long long int ll;

int n,x;long long ans;
multiset<int> ms;

int main(void){
   int t;cin>>t;
   while(t--){
    ms.clear();ans=0;
    cin>>n;
    while(n--)cin>>x,
    ms.insert(x),ms.insert(x),
    ms.erase(ms.begin()),ans-=x;
	 
   for(auto i:ms)ans+=i;cout<<ans;

   }
   return 0;
}