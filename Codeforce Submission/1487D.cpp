#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
const int mxn = 1e9 + 7;
map<int, int> mpp;
int both = 0;
std::vector<int> v;
//finding pythagoras triplet in O(k) complexcity where k is number of pythagoras triplet found
void triplet(int limit) {
    int a, b, c = 0;
    int m = 2;
    while (c < limit) {
        for (int n = 1; n < m; n++) {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;
            if (c > limit)
                break;

            if ((a * a) == ((2 * b) + 1)) {
                both++;
                //cout << c << " " << both << endll;
                mpp.insert({c, both});
                v.push_back(c);
            }
        }
        m++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    //precumputation
    triplet(mxn);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 5) {
            cout << 0 << endll;
        }
        else {
            auto it = find(v.begin(), v.end(), n);
            if (it == v.end()) {
                auto itt = lower_bound(v.begin(), v.end(), n);
                itt--;
                cout << mpp[*(itt)] << endll;
            }
            else {
                cout << mpp[*(it)] << endll;
            }
        }
    }
    return 0;
}