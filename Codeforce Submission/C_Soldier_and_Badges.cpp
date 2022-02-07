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


int main()
{
    FIO;
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int incre=0;
    // for(auto i:mp)
    // cout<<i.first<<" "<<i.second<<endl;

    for(auto i:mp){
        if(i.second>1){
            int num=i.first+1;
            while(i.second!=1){
                while(mp.find(num)!=mp.end()){
                    ++num;
                }
                //cout<<i.first<<" "<<num<<" "<<i.second-1<<endl;
                incre+=num-(i.first);
                mp[num]++;
                ++num;
                --i.second;
            }
        }
    }
    cout<<incre<<endl;
    return 0;
}