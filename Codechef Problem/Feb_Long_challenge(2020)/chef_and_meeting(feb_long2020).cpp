#include <bits/stdc++.h>
using namespace std;
#define  ll       long long
#define  endll    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//mt19937          rng(chrono::steady_clock::now().time_since_epoch().count());
//#define mod    1000000009
int hour24(string s) {
    string ans;
    if (s[6] == 'A') {
        if (s[0] == '1' && s[1] == '2') {
            ans = ans + "00" + s[3] + s[4];
        }
        else {
            ans = ans + s[0] + s[1] + s[3] + s[4];
        }
    }
    else {
        //12:00 AM 11:42 PMpm
        if (s[0] == '1' && s[1] == '2') {

            ans = ans + s[0] + s[1] + s[3] + s[4];
        }
        else {
            string kk;
            kk = kk + s[0] + s[1];
            int ikk = stoi(kk);
            ikk += 12;
            ans = ans + to_string(ikk);
            ans = ans + s[3] + s[4];
        }
    }
    int ians = stoi(ans);
    return ians;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
#endif
    FIO;
    int t;
    cin >> t;
    string nl;
    //after using cin before getline
    //cin doesnt clear the buffer for next input and buffer contain '\n' so we have to take input
    //whhich is '\n' to clear the buffer
    getline(cin, nl);//it contain '\n'
    //cout << main_time;
    while (t--) {
        string main_time;
        getline(cin, main_time);//contain 12:01 AM
        int imain_time = hour24(main_time);
        int n;
        cin >> n;
        getline(cin, nl);
        std::vector<string> v(n);
        int l[n], r[n];
        for (int i = 0; i < n; i++) {
            getline(cin, v[i]);
            string rl = v[i].substr(9, 17);
            string sl = v[i].substr(0, 8);
            l[i] = hour24(sl);
            r[i] = hour24(rl);
            //cout << imain_time << " " << l[i] << " " << r[i] << endll;
        }
        //now convert to 24hr
        for (int i = 0; i < n; i++) {
            if (imain_time >= l[i] && imain_time <= r[i])
                cout << 1;
            else
                cout << 0;
        }
        cout << endll;
    }
    return 0;
}