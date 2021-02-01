#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    int test;
    cin >> test;
    while (test--) {
        string s, t;
        cin >> s >> t;
        int l1 = s.length();
        int l2 = t.length();
        int lcm = (l1 * l2) / __gcd(l1, l2);
        //one way is to "ba" is part of "baba" and if true than find their LCM(which is difficult)
        //better way is find the LCM and than make 2 string one with using 's' and other with
        //using 't' and than compare them
        string a, b;
        for (int i = 0; i < lcm / l1; i++)
            a += s;
        for (int j = 0; j < lcm / l2; j++)
            b += t;
        if (a == b)
            cout << a;
        else
            cout << -1;
        cout << endll;
    }
    return 0;
}