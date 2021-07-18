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
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b((n * m), vector<int>(3));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
        b[k][0] = a[i][j];
        b[k][1] = i;
        b[k][2] = j;
        //cout << b[k][0] << " ";
        k++;
      }
      //cout << endl;
    }
    //cout << k << endl;
    sort(b.begin(), b.end());
    vector<vector<int>> ans(n, vector<int>(m, -1));
    //taking the m smallest number and placing it in mth places in increaseing order
    for (int i = 0; i < m; i++)
    {
      int x = b[i][1];
      int y = b[i][2];
      ans[x][i] = b[i][0];
      a[x][y] = -1;
    }

    for (int i = 0; i < n; i++)
    {
      int ii = 0;
      for (int j = 0; j < m; j++)
      {
        if (ans[i][j] != -1)
          cout << ans[i][j] << " ";
        else
        {
          //cout << "    " << ii << " ";
          for (int z = ii; z < m; z++)
          {
            if (a[i][z] != -1)
            {
              cout << a[i][z] << " ";
              ii = z + 1;
              break;
            }
          }
        }
      }
      cout << endl;
    }
  }
  return 0;
}