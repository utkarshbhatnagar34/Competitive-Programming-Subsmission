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

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in", "r", stdin);
   // freopen("output.in", "w", stdout);
#endif
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((max(a[i], a[i + 1]) - min(a[i], a[i + 1])) >= 2) {
                cout << "YES" << endl;
                cout << i + 1 << " " << i + 2 << endl;
                flag = 1; break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
        }
    }
    /*similar to the A in codeforces round 735
    lets suppose x,y<2 
    by adding z can it make the condition in qustion true
    x,y<2 means |x-y|=1 so on adding z if z=y+1 or z=x-1 (x,y,z)=>(x,y,y+1)<3 still

    if z=x-3 or z=x+3 than 
    (x,y,z)=>(x,x+1,x-3) or (x,x+1,x+3) ==3 which makes condition true
    but if we take any subarray of length 2 from it will also work so 
    it means that if subarray of length n is present than subarray of n-1 lenght will also be present
    
    in other words if subarray of 3 is true than subarray of length 2 is also true
    so we just have to search for the |ai-ai+1|>=2
    */
    return 0;
}