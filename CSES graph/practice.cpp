#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

int N, M, sx, sy;
vector<vector<int>> arr;
vector<vector<int>> visited;

vector<pair<int, int>> hori = {{ -1, 0}, {1, 0}}, verti = {{0, -1}, {0, 1}};

ll solve(int idx, int x, int y, string &direct) {
  if (x < 0 || x >= N || y < 0 || y >= M) return 0;
  int len=direct.size();
  if (idx == len) return arr[x][y];
  if (direct[idx] == 'L') {
    return arr[x][y] + solve(idx + 1, x - 1, y, direct) - 1;
  }
  else if (direct[idx] == 'R') {
    return arr[x][y] + solve(idx + 1, x + 1, y, direct) - 1;
  }
  else if (direct[idx] == 'U') {
    return arr[x][y] + solve(idx + 1, x, y - 1, direct) - 2;
  }
  else {
    return arr[x][y] + solve(idx + 1, x, y + 1, direct) - 2;
  }
}
ll solveMax(int x, int y,int picked) {
  if(visited[x][y]==2 && picked+1==N) return arr[x][y];
  ll ans=0,present=0;
  if(visited[x][y]==2) present=1;
  visited[x][y]=1;
  for(auto i:hori){
      int a=i.first+x,b=i.second+y;
      if((a>=0 && a<N && b>=0 &&b<M) && (visited[a][b]!=1))
        ans=max(ans,arr[x][y]+solveMax(a,b,picked+present)-1);
  }
  for(auto i:verti){
      int a=i.first+x,b=i.second+y;
      if((a>=0 && a<N && b>=0 &&b<M) && (visited[a][b]!=1))
        ans=max(ans,arr[x][y]+solveMax(a,b,picked+present)-2);
  }
  return ans;
}
int main()
{
  SPEED;
  string chr;
  cin >> N >> M;
  cin>>chr;
  sx=chr[0]-'0';sy=chr[2]-'0';
  arr.resize(N, vector<int>(M)); visited.resize(N, vector<int>(M));
  
  int x, y, w;
  for (int i = 0; i < N; i++) {
    cin>>chr;
    x=chr[0]-'0';y=chr[2]-'0';
    cin>> w;
    arr[x][y] = w;visited[x][y]=2;
  }
  string direct = ""; char ch = 'P';
  while (ch != 'Q') {
    cin >> ch;
    direct += ch;
  }
  direct.pop_back();
  ll maxPoint = solveMax(sx, sy,0);
  ll point = solve(0, sx, sy, direct);
  if(point ==maxPoint)
    cout<<"*** Mission Passed! ***";
  else
    cout<<"*** Mission failed! ***";
  return 0;
}