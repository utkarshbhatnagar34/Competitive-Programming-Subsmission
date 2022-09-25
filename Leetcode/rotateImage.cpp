#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define  SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
#define print(v)    {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define  endl       "\n"

void rotateImage(vector<vector<int>> &A) {
  int n = A.size();

  int l = 0, r = n - 1;

  while(l < r) {
    for(int i = 0; i < r-l; i++) {
      int top = l, bottom = r;

      int topLeft = A[top][l + i];

      A[top][l + i] = A[bottom - i][l];

      A[bottom - i][l] = A[bottom][r - i];

      A[bottom][r - i] = A[top + i][r];

      A[top + i][r] = topLeft;
    }
    l++; r--;
  }
}

int main()
{
    SPEED;
    int n;cin>>n>>n;
    vector<vector<int>> arr(n,vector<int> (n));

    for(int i =0; i < n; i++) {
      for(int j =0; j < n; j++) {
        cin>> arr[i][j];
      }
    }

    for(int i = 0;i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
    rotateImage(arr);

    for(int i = 0;i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}