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

  //input size of chess board
  vector<vector<int>> v;
  vector<int> left_diagonal, right_diagonal;
  vector<int> col;

  bool is_safe(int x, int y, vector<int> left_diagonal, vector<int> right_diagonal, vector<int> col)
  {
    //cout << "safe " << x << " " << y << endl;
    for (auto i : left_diagonal)
    {
      if ((x + y) == i)
        return false;
    }
    for (auto i : right_diagonal)
    {
      if (x - y == i)
        return false;
    }
    for (auto i : col)
    {
      if ((y) == i)
        return false;
    }
    return true;
  }

  bool place_queen(vector<vector<int>> &v, int n, int x)
  {

    if (x >= n)
    {
      // cout<<"  done  "<<endl;
      return true;
    }
    //cout<<"\n  start "<<x<<endl;
    for (int i = 0; i < n; i++)
    {
      //cout << x << "   " << i << endl;
      if (v[x][i] != 1)
      {
        if (is_safe(x, i, left_diagonal, right_diagonal, col))
        {
          v[x][i] = 1;
          col.push_back(i);
          right_diagonal.push_back(x - i);
          left_diagonal.push_back(x + i);
          // cout<<"before\n";
          // for(auto it:col)
          // cout<<it<<" ";
          // cout<<endl;
          // for(auto it:left_diagonal)
          // cout<<it<<" ";
          // cout<<endl;

          //cout << "\nchecking " << x << " " << i << " " << x - i << " " << x + i << endl;
          if (place_queen(v, n, x + 1))
          {
            return true;
          }
          //backtracking(undo our changes)
          v[x][i] = 0;
          col.pop_back();
          left_diagonal.pop_back();
          right_diagonal.pop_back();
          // cout<<"after\n";
          // for(auto it:col)
          // cout<<it<<" ";
          // cout<<endl;
          // for(auto it:left_diagonal)
          // cout<<it<<" ";
          // cout<<endl;
        }
      }
    }
    return false;
  }
  int main()
  {
    FIO;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
      v[i].resize(n, 0);

    place_queen(v, n, 0);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << v[i][j] << " ";
      cout << endl;
    }
    return 0;
  }