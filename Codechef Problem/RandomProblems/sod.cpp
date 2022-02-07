#include <bits/stdc++.h>
using namespace std;

typedef    long long ll;
typedef    long double lld;
typedef    unsigned long long ull;
typedef    pair<int, int> pii;

#define    all(v) (v).begin(),(v).end()
#define    sz(v) (int)(v).size()
#define    getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define    print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define    endl    "\n"
#define    SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
//const    lld pi = 3.14159265358979323846;
//#define  mod    1000000007

int main()
{
    SPEED;
    int t;
    cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        ll ans = 0;
        if(l==r){
          if(l%3==0)
          cout<<1<<endl;
          else
          cout<<0<<endl;
          continue;
        }
        if (l % 3 == 0)
            ans++;
        if (r % 3 == 0)
            ans++;
        ans += ((l % 3) + ((r - l) - 1)) / 3;
        cout << ans << endl;
    }
    return 0;
}