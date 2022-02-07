#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007
void longestPrefixSuffix(vector<int> &a,string str){
        if(str.size()==1) return;
        int i=0,j=1;
        while(i<j){
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
int main()
{
    string str="dafbkdaftdafbkdafb";
    int n=str.length();
    
    return 0;
}