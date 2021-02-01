#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;
    deque<int> d;
    int aa;
    int mx = INT_MIN;
    int pos;
    map<int, pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        cin >> aa;
        d.push_back(aa);
        if (mx < aa) {
            mx = aa;
            pos = i;
        }
    }
    // preforming operation
    int step = 0;
    int store1, store2;
    while (d.front() != mx)
    {
        store1 = d.front();
        d.pop_front();
        store2 = d.front();
        d.pop_front();
        if (store1 < store2) {
            d.push_back(store1);
            d.push_front(store2);
            v[step].first = store1;
            v[step].second = store2;
            step++;
        }
        else {
            d.push_back(store2);
            d.push_front(store1);
            v[step].first = store1;
            v[step].second = store2;
            step++;
        }
    }
    //query part
    deque<int>::iterator it = d.begin();
    int ii = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = d.front();
        d.pop_front();
    }
    for (int i = 0; i < q; i++) {
        ll m_j;
        cin >> m_j;
        if (m_j <= pos) {
            cout << v[m_j - 1].first << " " << v[m_j - 1].second << '\n';
        } else {
            //cout << (m_j - (step + 1)) % (n - 1) + 1 << endl;
            cout << mx << " " << a[(m_j - (step + 1)) % (n - 1) + 1] << '\n';
        }
    }
}
