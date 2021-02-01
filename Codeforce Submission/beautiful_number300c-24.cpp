#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

const ll p=1000000000+7;

int check(ll n,int a,int b)
{
    int c=0;
    int d;
    while(n>0)
    {
        d=n%10;
        n=n/10;
        if(d==a||d==b)
            c=1;
        else
        {
            c=0;
            break;
        }
    }
    return c;
}
ll power(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2!=0)
            res=((res%p)*(a%p))%p;

        a=((a%p)*(a%p))%p;
        b=b/2;
    }
    return res;
}
ll ncr(ll n,ll r,int *f)
{
    ll result=1;
    result=f[n];
    result=(result*1ll*power(f[r],p-2))%p;
    result=(result*1ll*power(f[n-r],p-2))%p;
    return result;
}
int main()
{
   int a,b;
   ll n;
   cin>>a>>b>>n;

   int f[n+1];
   f[0]=f[1]=1;
   for(int i=2;i<n+1;i++)
    f[i]=(f[i-1]*1ll*i)%p;


   ll s=0;
   ll cont=0;
   int c=0;
   for(ll i=0;i<=n;i++)
   {
       s=a*i+(n-i)*b;
       c=check(s,a,b);
       if(c==1)
       {
           cont=(cont+ncr(n,i,f))%p;
       }
   }
   cout<<cont;
   return 0;
}
