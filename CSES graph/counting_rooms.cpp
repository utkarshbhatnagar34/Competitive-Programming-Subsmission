#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pi = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};
int n, m;
void solve(vector<vector<bool>> &a, int x, int y) {
  if (!((x >= 0 && x < n) && (y >= 0 && y < m))) return;
  if (a[x][y] == false) return;
  a[x][y] = 0;
  
  for (auto i : pi) {
    solve(a, x + i.first, y + i.second);
  }
}
int main() {

  cin >> n >> m;
  vector<vector<bool>> a(n, vector<bool>(m)); char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch == '.') a[i][j] = 1;
      else a[i][j] = 0;
    }
  }
  int room = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        solve(a, i, j);
        room++;
      }
    }
  }
  cout << room << endl;
  return 0;
}