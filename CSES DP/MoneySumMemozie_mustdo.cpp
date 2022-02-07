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
set<int> st;
int n;
int dp[101][100001];
/*in this question I does not require to store anything but we still store dp[][] as in recurrsion states started repeating and 
to stop it we need to mark the visited state thats what we are doing here we are simply marking the visited states and not visited it again*/

int  solve(vector<int> &a, int idx, int sum) {
    //the only work it is doing is marking the states which are already visited and stop revisiting it again
    if (dp[idx][sum] != -1) return dp[idx][sum];

    if (idx == n) {
        st.insert(sum); return 1;
    }
    int op1 = solve(a, idx + 1, sum + a[idx]);
    int op2 = solve(a, idx + 1, sum);

    return dp[idx][sum] = op1 | op2;
}
int main()
{
    FIO;
    cin >> n;
    vector<int> a(n);
    int zr = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zr++;
    }
    solve(a, 0, 0);
    if (zr == 0) st.erase(0);
    cout << st.size() << endl;
    for (auto i : st)
        cout << i << " ";
    return 0;
}