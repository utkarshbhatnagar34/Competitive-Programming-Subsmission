#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mx=10000001;
int main() 
{
	
  int n;
  cin>>n;
  ll p[mx]={0};
	 
  for(ll i=3;i<mx;i+=2)
     p[i]=1;//marking as prime

   for(ll i=3;i<mx;i+=2)
   {
     if(p[i]==1)
     {
      for(ll j=i*i;j<mx;j+=i)
       p[j]=0;
     }
   }
   
   p[2]=1;
   p[0]=p[1]=0;
   int s=0;
   for(ll i=0;i<mx;i++)
   {
     if(p[i]==1)
      {
      	s++;
      	cout<<i<<" ";
      	if(s==n)
      	  break;
      }
   }
  
	return 0;
}
