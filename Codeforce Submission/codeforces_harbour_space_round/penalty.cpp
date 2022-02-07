#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
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
        string s;
        cin >> s;
        int n = 10;

        int a = 0, b = 0;
        int opta = 0, optb = 0;
        int rema = 5, remb = 5;
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 != 0) {
                if (s[i] == '1' || s[i] == '?')
                    a++;
                if (s[i] == '?')
                    opta++;
                rema--;
            }
            else {
                if (s[i] == '1' || s[i] == '?')
                    b++;

                if (s[i] == '?')
                    optb++;
                remb--;
            }

            if (a > (b - optb) + remb) {
                cout << i + 1 << endl; flag = 1; break;
            }

            if (b > (a - opta) + rema) {
                cout << i + 1 << endl; flag = 1; break;
            }

        }
        if (flag == 0)
            cout << 10 << endl;
    }
    return 0;
}