#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define endl "\n"
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
//const lld pi = 3.14159265358979323846;
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
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> lef(n, 0), rig(n, 0), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            if (i + 1 <= l)
            {
                lef[c[i] - 1]++;
            }
            else
            {
                rig[c[i] - 1]++;
            }
        }
        //unq => unique color
        vector<int> unq = c;
        sort(unq.begin(), unq.end());
        auto ip = unique(unq.begin(), unq.end());
        unq.resize(distance(unq.begin(), ip));
        //removing matching pairs
        for (auto i : unq)
        {
            int k = min(lef[i - 1], rig[i - 1]);
            lef[i - 1] -= k;
            rig[i - 1] -= k;
            l -= k;
            r -= k;
        }
        //now after removing all matching pairs only those socks are left which have Ci color and only left/right
        ll cost = 0;
        //if left==right than only we have to convert them to same color or convert left to right
        if (l == r)
            cost += l;
        else
        {
            //if l>r than we have to convert (l-r)/2 left socks to right
            //so ith color left sock is 5 than 5/2=2 convert to right sock and 2 same color sock are used to make a matching pair
            //means in total 4 sock are utilized but 1 is left which added to extra
            //(when left=right)to untilise this extra(left sock) we can change its color to corresponding right sock()
            //(when left>right)than take extra sock convert to right sock than change it to reqiued color till left!=right
            if (r > l)
            {
                swap(l, r);
                auto temp = rig;
                rig = lef;
                lef = temp;
            }
            //left>right
            int convert = (l - r) / 2;
            int extra = 0;
            for (int i = 0; i < lef.size(); i++)
            {
                if (convert < 0)
                    break;

                int change = min(lef[i] / 2, convert);
                convert -= change;
                cost += change;
                l -= change * 2;
                if (lef[i] & 2)
                    extra++;
            }

            if (convert > 0)
            {
                extra -= convert * 2;
                cost += convert * 2;
            }
            cost += r;
        }
        cout << cost << endl;
    }
    return 0;
}