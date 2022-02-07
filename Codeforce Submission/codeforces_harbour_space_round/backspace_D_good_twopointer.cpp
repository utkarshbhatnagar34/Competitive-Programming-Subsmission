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
//problem link-https://codeforces.com/contest/1553/problem/D 
bool check(string s, string t)
{
    int n = s.length();
    int len = t.length();
    int tt = 0, cur = 0;

    while (tt < len && cur < n) {
        if (s[cur] == t[tt]) {
            cur++; tt++;
        }
        else {
            cur += 2;
        }
    }
    if (tt == len) {
        return true;
    }
    else
        return false;
}
int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in", "r", stdin);
    //freopen("output.in", "w", stdout);
#endif
    FIO;
    int test;
    cin >> test;
    while (test--) {
        string s, t; cin >> s >> t;
        int n = s.length();
        int len = t.length();

        /*pos are the starting points of the string t
          distane between two character should be even to be deleted
          problem in starting from front is that s=aababa t=ababa if we chose first a(at 0)
          than we cannot chose b from s so we have to chose a(at 1 pos) after that we can easily chose b
          we have to do it in O(n) complexity so we cannot start from the front as it contain many starting point
          instead we chose to select from the back as in front we can delete as many character we want
          */
        bool flag = 0;
        reverse(all(s)); reverse(all(t));
        if (check(s, t)) {
            flag = 1;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}