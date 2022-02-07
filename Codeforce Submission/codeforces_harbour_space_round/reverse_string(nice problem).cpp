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

bool check(int start, string s, string t) {
    int n1 = s.length();
    int n2 = t.length();
    bool flag = 0;

    int k;
    for (int i = start; i < n1 && (i - start) + 1 <= n2; i++) {
        string a, b;
        if ((i - start) + 1 < n2) {
            a = s.substr(start, (i - start) + 1);
            k = n2 - ((i - start) + 1);
            if ((i + 1) - k > 0) {
                b = s.substr(i - k, k);
                reverse(b.begin(), b.end());
                a = a + b;
                if (a == t)
                    return true;
            }
        }
        else {
            a = s.substr(start, (i - start) + 1);
            if (a == t)
                return true;
        }

    }
    return false;
}
int main()
{
    FIO;
    int test;
    cin >> test;
    while (test--) {
        string s, t; cin >> s >> t;
        int n1 = s.length();
        int n2 = t.length();

        vector<vector<int>> pos(26);
        int alpha[26] = {0};
        for (int i = 0; i < n1; i++) {
            int k = s[i] - 'a';
            alpha[k]++;
            pos[k].push_back(i);
        }


        int k = t[0] - 'a';
        if (alpha[k] == 0) {
            cout << "NO" << endl;
            continue;
        }
        bool flag = 0;
        for (int i = 0; i < pos[k].size(); i++) {
            if (check(pos[k][i], s, t)) {
                cout << "YES" << endl;
                flag = 1; break;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
    }
    return 0;
}