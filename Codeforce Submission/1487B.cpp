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
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int rem;
        //if n even it never meet
        if (n % 2 == 0) {
            rem = k % n;
            if (rem != 0)
                cout << rem << endll;
            else
                cout << n << endll;
        }
        else {
            //they meet after every (n-1)/2 move
            //since we are not counting the initial postion as the 1st move so we make k-1/colli
            //colli is the interval after which collision happen
            int colli = (n - 1) / 2;
            //meet is the number of collision actually happen
            int meet = (k - 1) / colli;
            //so after we collision position of B increase by 1 so total increase in postion of B is number of meeting of B have done
            int pos_b = (k + meet) % n;

            if (pos_b == 0)
                pos_b = n;
            cout << pos_b << endll;

        }
    }
    return 0;
}