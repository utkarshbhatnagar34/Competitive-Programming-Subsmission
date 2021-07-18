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
        int h, w; cin >> h >> w;

        vector<std::vector<int>> v(h, vector<int>(w, 0));
        //h-row w-col
        if (w >= h) {
            //first row
            for (int j = 0; j < h - 2; j += 2) {
                for (int i = 0; i < w; i++) {
                    if (i % 2 == 0 && (j == 0 || j == h - 1))
                        v[j][i] = 1;
                    else if (j != 0 && (i == 0 || i == w - 1))
                        v[j][i] = 1;
                }
            }
            //last row
            for (int i = 0; i < w; i++) {
                if (i % 2 == 0)
                    v[h - 1][i] = 1;
            }
        }
        else {
            for (int i = 0; i < w - 2; i += 2) {
                for (int j = 0; j < h; j++) {
                    if (i == 0 && j % 2 == 0)
                        v[j][i] = 1;
                    else if (i != 0 && (j == 0 || j == h - 1))
                        v[j][i] = 1;
                }
            }
            //last row
            for (int i = 0; i < h; i++) {
                if (i % 2 == 0)
                    v[i][w - 1] = 1;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cout << v[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}