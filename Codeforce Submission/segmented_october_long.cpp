#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;

ll power(int a,int b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
            result*=(long)a;
        a*=a;
        b/=2;
    }
    return result;
}

ll operation(int x,int y)
{
    if(x==y)
        return 0;
    else
    {
        int n=x^y;
        int msb=0;int cont=0;
        while(n!=0)
        {
            if(n&1==1)
                msb=cont;
            n=n>>1;
            cont++;
        }
        ll k=power(2,msb);
        return k;
    }
}

ll f_b(vector<int> a,int n)
{
    ll k=operation(a[0],a[1]);
    if(n<3)
        return k;
    else
    {
        int i=2;
        while(i<n)
        {
            k=operation(k,a[i]);
            i++;
        }
        return k;
    }
}
int main()
{
   int n;
   cin>>n;
   ll sum=0;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       sum=(sum+operation(a[i],0))%mod;
   }
   cout<<sum<<endl;
   vector<int> v;
   int siz=0;
   for(int i=0;i<n;i++)
   {//clear vector here
       v.clear();
       siz=1;
       v.push_back(a[i]);
       for(int j=i+1;j<n;j++)
       {
           v.push_back(a[j]);
           siz++;
           sum=(sum+f_b(v,siz))%mod;
       }
   }
   cout<<sum;
   return 0;
}
