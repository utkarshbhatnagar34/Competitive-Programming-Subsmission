#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
    }
#define print(v)              \
    {                         \
        for (auto i : v)      \
            cout << i << " "; \
        cout << endl;         \
    }
#define endl "\n"
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007
bool comparator(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0])
    {
        if (a[1] >= b[1])
            return true;
        else
            false;
    }
    return false;
}
bool isvalid(vector<vector<int>> v, int power)
{
    for (int i = 0; i < sz(v); i++)
    {
        if (power < v[i][0])
            return false;
        power += v[i][1];
    }
    return true;
}
int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            int a[k];
            int power = 0;
            for (int i = 0; i < k; i++)
            {
                cin >> a[i];
                if (power + i < a[i])
                {
                    power = a[i] - i + 1;
                }
            }
            v[i][0] = power;
            v[i][1] = k;
        }
        sort(all(v), comparator);
        int ans=v[0][0],power=ans+v[0][1];
        for(int i=1;i<n;i++){
            if(power<v[i][0]){
                ans+=v[i][0]-power;
                power+=v[i][0]-power;
            }
            power+=v[i][1];
        }
        cout<<ans<<endl;
    }
    return 0;
}