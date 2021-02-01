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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n = n * 2;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n, greater<int>());
        //maximum is always removed first
        int mx1 = a[0];
        //first,second
        int f, s;
        int x; bool flag, flag1 = false;
        //used multiset as in it elements are stored in desending order so easy to remove
        multiset<int, greater<int>> mset;
        //to store pairs
        vector<pair<int, int> > p;
        for (int i = 1; i < n; i++) {
            f = mx1; s = a[i];
            //clear statement is nessacary(important)
            mset.clear();
            p.clear();
            //storing remaining element in the multiset
            for (int j = 1; j < n; j++) {
                //(important)check using index only or it remove every instance of the number we are removing
                if (i != j)
                    mset.insert(a[j]);
            }
            //checking if condition is true or not
            x = f;
            flag = true;
            while (!mset.empty()) {
                multiset<int, greater<int>>::iterator it1 = mset.begin();
                int tem1 = *it1;
                //(important)
                //always erase using iterator as it store the address of the position to remove
                //if we put eg-mset.erase(30) it will erase all the 30 present in the multilset
                mset.erase(it1);
                multiset<int, greater<int>>::iterator it2 = mset.find(x - tem1);
                p.push_back({tem1, *(it2)});
                if (it2 != mset.end()) {
                    mset.erase(it2);
                }
                else {
                    flag = false;
                    break;
                }
                x = tem1;
            }
            if (flag) {
                cout << "YES\n" << (f + s) << endll;
                cout << f << " " << s << endll;
                flag1 = true;
                break;
            }
        }
        if (flag1) {
            for (int i = 0; i < p.size(); i++) {
                cout << p[i].first << " " << p[i].second << endll;
            }
        }
        else
            cout << "NO" << endll;
    }
    return 0;
}