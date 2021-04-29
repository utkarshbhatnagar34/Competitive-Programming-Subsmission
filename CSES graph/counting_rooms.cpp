#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define endl "\n"
#define FIO                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

int n, m, room = 0;
vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y)
{
  if (x >= 0 && y >= 0 && x < n && y < m)
  {
    //cout << x << "ok " << y << endl;
    return true;
  }
  else
  {
    //cout << x << " no" << y << endl;
    return false;
  }
}
void dfs(vector<vector<bool>> &visited, int x, int y)
{
  visited[x][y] = false;
  int i = 0;
  for (auto it : moves)
  {
    //cout << " " << x + it.first << " " << y + it.second << endl;
    if (valid(x + it.first, y + it.second))
    {
      //cout << "    " << x + it.first << " " << y + it.second << endl;
      if (visited[x + it.first][y + it.second])
      {
        //cout << " " << x - it.first << " " << y - it.second << endl;
        dfs(visited, x + it.first, y + it.second);
      }
    }
  }
}

int main()
{
  FIO;
  cin >> n >> m;
  vector<vector<bool>> visited(n, vector<bool>(m, true));
  char ch;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> ch;
      if (ch == '#')
        visited[i][j] = false;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (visited[i][j])
      {
        visited[i][j] = false;
        //cout << i << " " << j << endl;
        dfs(visited, i, j);
        room++;
      }
    }
  }
  cout << room;
  return 0;
}