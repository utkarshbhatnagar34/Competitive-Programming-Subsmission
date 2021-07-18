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
        ll n; cin >> n;
        ll a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];


        sort(a, a + n, greater<ll>());
        sort(b, b + n, greater<ll>());

        ll req = n - (n / 4);

        ll bob = 0, liya = 0;
        for (int i = 0; i < req; i++) {
            bob += a[i]; liya += b[i];
        }

        if (bob >= liya) {
            cout << 0 << endl; continue;
        }
        //cout << bob << " " << liya << endl;
        ll ori = n;
        ll bb = req;
        while (bob < liya)
        {
            n++;
            if (n % 4 == 0)
            {
                if (req - 1 >= 0) {
                    bob += 100;
                    bob -= a[req - 1];
                    req--;
                }
            }
            else
            {
                bob += 100;
            }

            //liya
            if (n % 4 != 0 && bb < ori) {
                liya += b[bb]; bb++;
            }
            //cout << bob << " " << liya << endl;
        }
        cout << n - ori << endl;
    }
    return 0;
}