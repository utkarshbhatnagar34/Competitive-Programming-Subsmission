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
//problem link
// https://codeforces.com/contest/1552/problem/B

const int N = 1e5 + 5;
int a[N][5];
//use 2D array instead of vector because 2D is giving TLE
//2D array is much more optimed
//similar problem in d.e. shaw
int better(int x, int y) {
    int one = 0, two = 0;
    for (int i = 0; i < 5; i++) {
        if (a[x][i] < a[y][i]) {
            one++;
        }
        else
            two++;
        if (one == 3 || two == 3)
            break;
    }
    return one > two ? x : y;
}
int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        if (n == 1) {
            cout << 1 << endl; continue;
        }
        //one athele is superior than all other athelte when he is perform in well in altest 3 races
        //if somone is superior means he better than all of them

        //lets assume 1st athelte is superior than all ,than keep on checking with next one
        //and updating it in the end we get some athelte which may be the best

        int best = 0;
        for (int i = 1; i < n; i++) {
            best = better(best, i);
        }

        //but to confirm it we must check it with all other athelte
        //ex 2 is better than 1 so best =2 than 5 is better than 2,3,4, so best=5
        //but 1 better than 5 its means no one is best
        int ans;
        for (int i = 0; i < n; i++) {
            if (i == best)
                continue;
            ans = better(best, i);
            if (ans != best) {
                ans = -2; break;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}