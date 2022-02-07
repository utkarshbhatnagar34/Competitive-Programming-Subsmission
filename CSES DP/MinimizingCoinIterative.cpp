#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define  endl           "\n"
#define  all(v)         (v).begin(),(v).end()
#define  sz(v)          (int)(v).size()
#define  getunique(v)   {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  print(v)       {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  FIO            ios_base::sync_with_stdio(0); cin.tie(0);
//#define mod           1000000007
int inf = 1e6 + 1;
int main()
{
    FIO;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[x + 1];
    for (int i = 0; i <= x; i++) dp[i] = inf;
    dp[0] = 0;
    //dp[i] can this position can be reached
    //top down
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i + a[j] <= x)
                dp[i + a[j]] = min(dp[i + a[j]], dp[i] + 1);
        }
    }
    if (dp[x] == inf) cout << -1 << endl;
    else cout << dp[x] << endl;
    return 0;
}