#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define endl "\n"
#define FIO                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009
int main()
{
  FIO;
  string s = "abcd";
  cout<<int(s[0] - 'a')<<endl;
  vector<pair<int, int>> mp(26);
  std::fill(mp.begin(), mp.end(), 0);
  mp[int(s[0] - 'a')].first++;
  cout << mp[0].first << endl;
  return 0;
}