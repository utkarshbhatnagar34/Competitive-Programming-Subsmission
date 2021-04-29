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
        int a, b, c;
        cin >> a >> b >> c;
        //there are maximum 7 cases are possible a,b,c,ab,ac,bc,abc
        //if a,b,c are greater than 4 than all 7 cases are possible
        if (a >= 4 && b >= 4 && c >= 4) {
            cout << 7 << endll;
        }
        else {
            int ans = 0;
            //these 3 cases are always be checked first greedly
            if (a > 0) {
                ans++; a--;
            }
            if (b > 0) {
                ans++; b--;
            }
            if (c > 0) {
                ans++; c--;
            }
            int k[] = {a, b, c};
            int sum = 0;
            int ori = ans;
            //now checking for ab,ac,bc case which optimal
            for (int i = 0; i < 3; i++) {
                sum = 0; k[0] = a; k[1] = b; k[2] = c;
                //this loop check for [ab,ac] or [ab,bc] or [ac,bc] are possible or not
                //but it is not checking for that all three ab,ac,bc are possible all together or not
                for (int j = 0; j < 3; j++) {
                    if (i != j) {
                        if (k[i] > 0 && k[j] > 0) {
                            sum++;
                            k[i]--;
                            k[j]--;
                        }
                    }
                }
                //checking for the test case that is not checked in above for loop
                if (i != 0 && i != 1 && k[0] > 0 && k[1] > 0) {
                    sum++;
                }
                else if (i != 0 && i != 2 && k[0] > 0 && k[2] > 0)
                    sum++;
                else if (i != 1 && i != 2 && k[1] && k[2])
                    sum++;

                ans = max(ans, ori + sum);
            }
            cout << ans << endll;
        }
    }
    return 0;
}