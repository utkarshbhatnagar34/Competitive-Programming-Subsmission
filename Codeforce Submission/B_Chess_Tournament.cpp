#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007
void printans(vector<vector<char>> ans, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
}
int main()
{
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int one = 0, two = 0;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                one++;
            else {
                idx.push_back(i);
                two++;
            }
        }
        vector<vector<char>> ans(n, vector<char>(n, 'X'));
        if (two == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        ans[i][j] = '=';
                    }
                }
            }
            cout << "YES" << endl;
            printans(ans, n);
        }
        else if (two <= 2) {
            cout << "NO" << endl;
        }
        else {
            //1->2
            ans[idx[0]][idx[1]] = '+';
            ans[idx[1]][idx[0]] = '-';
            //2->3
            ans[idx[1]][idx[2]] = '+';
            ans[idx[2]][idx[1]] = '-';

            for (int i = 0; i < n; i++) {
                if (ans[idx[0]][i] == 'X' && i != idx[0])
                    ans[idx[0]][i] = '-';
            }
            for (int i = 0; i < n; i++) {
                if (i != idx[0] && ans[i][idx[0]] == 'X') {
                    ans[i][idx[0]] = '+';
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && ans[i][j] == 'X')
                        ans[i][j] = '=';
                }
            }
            cout << "YES" << endl;
            printans(ans, n);
        }
    }
    return 0;
}