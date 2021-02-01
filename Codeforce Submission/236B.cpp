#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll m=1073741824;

int divi(int n)
{
    int d=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int ct=0;
            while(n%i==0)
            {
                n=n/i;
                ct++;
            }
            d*=(ct+1);
        }
    }
    if(n!=1)
    d*=2;

    return d;
}
int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int d;
   ll s=0;
   for(int i=1;i<=a;i++)
   {
       for(int j=1;j<=b;j++)
       {
           for(int k=1;k<=c;k++)
           {
              d=i*j*k;
              s=(s+divi(d))%m;
           }
       }
   }
   cout<<s;
   return 0;
}
