#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

ll nc2(ll n) {
    if (n == 0)
        return 1;

    ll pro = (n * (n - 1)) / 2;
    return pro;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    ll n, k;
    cin >> n >> k;
    while (n != -1 && k != -1) {
        ll q = nc2(n);
        ll n1, sum = 0, p;
        if (k & 1) {
            n1 = ceil(float(k) / 2);
            sum = (n1 * (n1 - 1)) / 2;
            if (n1 - 2 > 0) {
                sum += ((n1 - 1) * (n1 - 2)) / 2;
            }
            p = sum;
        }
        else {
            n1 = k / 2;
            ll sum = (n1 * (n1 - 1));
            p = sum;
        }
        if (p != 0) {
            //cout << " " << p << endl;
            ll hcf = __gcd(p, q);
            p = p / hcf;
            q = q / hcf;
            cout << p << "/" << q << endl;
        }
        else
            cout << 0 << endl;
        cin >> n >> k;
    }
    return 0;
}
/*
solution:

1 2 3 ...k-3 k-2 k-1 k ....

we can pair k-1,1 only
(k-2,1) , (k-2,2)
(k-3,1),(k-3,2),(k-3,3)
.... and so on.

To reduce it into p/q form we divide by gcd(p,q)
*/