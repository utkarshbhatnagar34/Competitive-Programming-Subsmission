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
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> b(n + 1, 0); //giving
        vector<int> taken(n + 1, 0);//elements which is already assigned

        //assigning elements according to their wishes
        for (int i = 1; i <= n; i++) {
            if (taken[a[i]] == 0) {
                b[i] = a[i];
                taken[a[i]] = i;
            }
        }

        //storing elements which are not taken
        vector<int> not_taken;
        for (int i = 1; i <= n; i++) {
            if (taken[i] == 0)
                not_taken.push_back(i);
        }
        
        //now iterating over them which are not giving yet
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 0) {
                //not giving anybody

                //i is self loop means i is not giving anybody and not taking from anybody
                if (i == not_taken.back()) {
                  //when its the only elements is left
                    if (not_taken.size() == 1) {
                        b[i] = a[i];
                        b[taken[a[i]]] = i;
                        break;
                    }
                    else {//when their is self loop but more than one element is left 
                        swap(not_taken.back(), not_taken[0]);
                    }
                }
                //assigning it 
                b[i] = not_taken.back();
                not_taken.pop_back();
            }
        }

        //now checking whose wishes are fullfilled
        int fullfill = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] == a[i])
                ++fullfill;
        }
        cout << fullfill << endl;
        for (int i = 1; i <= n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}