#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"


int main()
{
    SPEED;
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
        cin>>a[i];

    int cost=0;
    int i=0;
    int ans=((n-1)*a[0])+((n-1)*(n-1)*(a[0]*a[0]));
    for(int k=1;k<n;k++){
      if(a[k]<=a[i]){
        cost+=((k-i)*a[i])+((k-i)*(k+i)*(a[i]*a[i]));
        i=k;
      }
    }
    if(i!=n-1){
      int k=n-1;
      cost+=((k-i)*a[i])+((k-i)*(k+i)*(a[i]*a[i]));
    }
    cout<<min(cost,ans)<<endl;
    return 0;
}