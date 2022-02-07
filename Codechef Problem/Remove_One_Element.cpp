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
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n - 1);
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        for (int i = 0; i < n - 1; i++)
            cin >> b[i];

        sort(all(a)); sort(all(b));
        int k = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = b[k] - a[i];
            //cout<<x<<" "<<k<<endl;
            if (x <= 0) {
              continue;
            }
           // cout<<x<<endl;
            bool flag = 1;
            for (int j = 0; j < n-1; j++) {
                if (st.find(b[j] - x) == st.end()) {
                   // cout<<x<<" "<<b[j]<<endl;
                    flag = 0; break;
                }
            }
            if (flag) {
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}