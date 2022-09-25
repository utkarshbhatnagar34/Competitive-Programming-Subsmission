#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"


int main()
{
    SPEED;
    int T;
    cin >> T;
    while (T--) {
        int N; cin >> N;
        string s; cin >> s;
        vector<int> D(N);

        for (int i = 0; i < N; i++)
            cin >> D[i];

        priority_queue<int> maxheap;
        bool flag = 1; int move = 0;

        for (int i = 0; i < N; i++) {
            if (s[i] == 'B') {
                if (maxheap.size() == 0) {
                    flag = 0;
                    break;
                }
                int pos = maxheap.top(); maxheap.pop();
                if (pos < i) {
                    flag = 0;
                    break;
                }
                move++;
                
                while (i <= pos && i < N) {
                    s[i] = 'R';
                    maxheap.push(D[i] + i);
                    i++;
                }
                i--;
            }
            else {
                maxheap.push(D[i] + i);
            }
        }

        if (flag)
            cout << move << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}