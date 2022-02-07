#include<bits/stdc++.h>
using namespace std;

void longestPrefixSuffix(vector<int> &a,string str){
        if(str.size()<=1) return;
        int i=0,j=1,n=str.length();
        while(j<n&&i<j){
            if(str[i]==str[j]){
                a[j]=i+1;
                i++;j++;
            }
            else{
                if(i==0)
                    j++;
                else{
                    i=a[i-1];
                }
            }
        }
    }
int main(){
  string s="issip";
  vector<int> a(s.length());
  longestPrefixSuffix(a,s);
  for(int i:a) cout<<i<<" ";
}