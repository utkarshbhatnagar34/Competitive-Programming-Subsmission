#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    int w;
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        cin>>w;
        if(w==100)
            x++;
        else
            y++;
    }
     if(x==0||y==0)
     {
         if(x%2==0&&y%2==0)
            cout<<"YES";
         else
            cout<<"NO";
     }
     else if(y%2!=0)
     {
         if(x%2==0)
            cout<<"YES";
         else
            cout<<"NO";
     }
     else
     {
         if(x%2==0)
            cout<<"YES";
         else
            cout<<"NO";
     }
    return 0;
}
