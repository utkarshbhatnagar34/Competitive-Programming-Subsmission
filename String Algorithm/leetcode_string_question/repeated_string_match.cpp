#include<bits/stdc++.h>
using namespace std;
 void PrefixSuffix(string s,vector<int> &a){
        int i=0,j=1,n=s.length();
        if(n<2) return;
        while(j<n&&i<j){
            if(s[i]==s[j]){
                a[j]=i+1;
                ++i;++j;
            }
            else{
                if(i==0)
                    j++;
                else{
                    i=a[j-1];
                }
            }
        }
    }
    int repeatedStringMatch(string a, string b) {
        int n1=a.length(),n2=b.length();
        vector<int> prefix(n2+2);
        PrefixSuffix(b,prefix);
        int j=0;
        cout<<"ok";
        // for(int i=0;i<n1;){
        //     while(j<n2&&a[(i+j)%n1]==b[j])
        //         j++;
            
        //     cout<<i<<" "<<j<<endl;
        //     if(j==n2){
        //         return ceil(float(i+n2)/n1);
        //     }
        //     if(j==0){
        //         i+=1;
        //     }
        //     else{
        //         i+=max(1,j-prefix[j-1]);
        //         j=a[j-1];
        //     }
        // }
        return -1;
    }
int main(){
  string a="aaac",b="aac";
  cout<<"ok";
  repeatedStringMatch(a,b);
}