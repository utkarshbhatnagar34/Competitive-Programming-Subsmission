#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);
ll power(ll a){
  ll result=1;int b=3;
  while(b>0){
    if(b&1)
      result=result*a;
    a=a*a;
    b/=2;
  }
  return result;
}
int main(){
  SPEED;
  vector<ll> v;
  ll i=1,num=1;
  while(num<1000000000000){
    v.push_back(num);
    i++;
    num=power(i);
  }
  int test;cin>>test;
  while(test--){
    ll x;cin>>x;
    bool flag=0;
    //now i have to just binary search the closed cube less than x
    for(int i=0;i<v.size();i++){
      if(x-v[i]<=0) break;

      if(binary_search(v.begin(),v.end(),x-v[i])){
        flag=1;break;
      }
    }
    //cout<<v.size()<<" "<<i<<" ";
    if(flag)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
}