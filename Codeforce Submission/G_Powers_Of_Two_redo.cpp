#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define  endl    "\n"
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007
//to find highest power of two closest to n (eg:n=10  return->8)
 
int main()
{
    FIO;
    int n,k;cin>>n>>k;
    int on=__builtin_popcount(n);
    if(on>k){
        cout<<"NO"<<endl;return 0;
    }
    if(k==n){
        cout<<"YES"<<endl;
        while(n){
            cout<<1<<" ";--n;
        }
        cout<<endl;return 0;
    }
    if(k>n){
        cout<<"NO"<<endl;return 0;
    }
    priority_queue<int> pq;
    for(int i=0;i<=30;i++){
        int num=1<<i;
        if((1<<i)&n)
           pq.push(num);
    }
    if(on==k){
        cout<<"YES"<<endl;
        while(pq.size()!=0){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        return 0;
    }
    while(pq.size()!=k){
        int num=pq.top();
        num/=2;
        pq.pop();
        pq.push(num);pq.push(num);
    }
    cout<<"YES"<<endl;
    while(pq.size()!=0){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}