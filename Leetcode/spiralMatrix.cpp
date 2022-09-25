#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define print(v) {for(auto i:v) cout<<i<<" "; cout<<endl;}

vector<int> spiralOrder(const vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    
    vector<int> ans(n * m);
    
    int left = 0, right = m - 1, top = 0, bottom = n - 1,  idx = 0;
    
    while(idx< n*m && left<=right && top<=bottom) {
        
        //left -> right 
        for(int i = left;idx< n*m && i < right; i++)
           ans[idx++] = A[top][i];
        //top -> bottom
        for(int i = top;idx< n*m && i < bottom; i++)
          ans[idx++] = A[i][right];
        //right ->left
        for(int i = right;idx< n*m && i > 0; i--)
           ans[idx++] = A[bottom][i];
        //bottom -> top
        for(int i = bottom;idx< n*m && i > top; i--)
          ans[idx++] = A[i][left];
          
        left++; right--; 
        top++; bottom--;
    }
    if(idx == m*n-1)
      ans[idx++] = A[n/2][m/2];
    return ans;
}

int main()
{
    int n, m;cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    int ele=1;
    for(int i =0; i < n; i++) {
      for(int j =0; j < m; j++) {
        arr[i][j]=ele++;
      }
    }

    for(int i = 0;i < n; i++) {
      for(int j = 0; j < m; j++) {
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
    vector<int> ans=spiralOrder(arr);

    print(ans);
    return 0;
}