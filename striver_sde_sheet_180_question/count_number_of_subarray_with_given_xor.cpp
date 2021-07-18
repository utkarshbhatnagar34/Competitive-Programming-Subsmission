#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;

#define all(v) (v).begin(), (v).end()
#define getunique(v)                  \
  {                                   \
    sort(all(v));                     \
    v.erase(unique(all(v)), v.end()); \
  }
#define endl "\n"

int main()
{
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int prefix[n];
  prefix[0] = a[0];

  int count = 0;
  if (prefix[0] == m)
    count++;

  for (int i = 1; i < n; i++)
  {
    prefix[i] = a[i] ^ prefix[i - 1];
    if (prefix[i] == m)
      count++;
  }

  int temp;
  unordered_map<int,int> s;
  for (int i = 1; i < n; i++)
  {
    temp = m ^ prefix[i];
    if(s.find(temp)!=s.end())
      count+=s[temp];

    s[prefix[i]]++;
  }
  cout<<count;
}