#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define  endl    "\n"
#define  FIO      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000007

//good question on binary search and prefix sum

void prefixSum2D(vector<vector<int>> a, vector<vector<int>> &prefix, int R, int C, int k)
{
   prefix[0][0] = a[0][0];

   // Filling first row and first column
   for (int i = 1; i < C; i++)
      prefix[0][i] = prefix[0][i - 1] + a[0][i];
   for (int i = 1; i < R; i++)
      prefix[i][0] = prefix[i - 1][0] + a[i][0];

   // updating the values in the cells
   for (int i = 1; i < R; i++) {
      for (int j = 1; j < C; j++) {
         prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1]
                        - prefix[i - 1][j - 1] + a[i][j];
      }
   }
}


int main()
{
   FIO;
   int t;
   cin >> t;
   while (t--) {
      int n, m, k; cin >> n >> m >> k;

      vector<pii> move(n * m);

      for (int i = 0; i < n * m; i++) {
         int x, y;
         cin >> x >> y;
         move[i].first = x - 1;
         move[i].second = y - 1;
      }

      int l = 0, r = (n * m) - 1, mid;
      int win=k*k;
      bool flag=0;
      int ans=-1;
      while (l <= r) {
         mid = l + (r - l) / 2;

         vector<vector<int>> a(n, vector<int>(m, 0));
         vector<vector<int>> prefix(n, vector<int>(m, 0));

         for (int i = 0; i <= mid; i++) {
            int x = move[i].first, y = move[i].second;
            if (i % 2 == 0)
               a[x][y] = 1; //alice at even postion
            else
               a[x][y] = -1; //bob at odd postion
         }

         prefixSum2D(a, prefix, n, m, k);
         int result=0;
         int R=n,C=m;
         int both=0;
         for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
               int sum = prefix[i][j];
               both=0;
               int x = -2, y = -2;
               if (i - k >= 0) {
                  x = i - k;
                  both++;
                  sum -= prefix[x][j];
               }

               if (j - k >= 0) {
                  y = j - k;
                  both++;
                  sum -= prefix[i][y];
               }
               if (both==2) {
                  sum += prefix[x][y];
               }

               if(abs(sum)==win){
                  result++;
               }
            }
         }
         //cout<<mid<<" "<<result<<endl;
         if(result>0){
            ans=mid;
            r=mid-1;
         }
         else{
            l=mid+1;
         }
      }
     if(ans==-1){
        cout<<"Draw"<<endl;
     }
     else{
        if(ans%2==0)
        cout<<"Alice"<<endl;
        else
        cout<<"Bob"<<endl;
     }
   }
   return 0;
}