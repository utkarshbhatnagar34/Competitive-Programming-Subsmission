#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

vector<vector<int>> ans;

void solve(int  &N,int mask, vector<int> v) {
    if(v.size() == N){
        ans.push_back(v); return ;
    }

    for(int i=1; i <=N; i++){
        if((mask&(1<<i))==0){
            v.push_back(i);
            solve(N, mask|(1<<i), v);
            v.pop_back();
        }
    }
}

int main()
{
    SPEED;
    int N;
    cin>>N;
    vector<int> v;
    solve(N,0,v);
    for(auto i:ans) {
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}