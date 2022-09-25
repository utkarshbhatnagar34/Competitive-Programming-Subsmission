#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class NumArray {
public:
    int N;
    vector<ll> tree;
    NumArray(vector<ll>& nums) {
        int n = nums.size();
        while (__builtin_popcount(n) != 1) n++;
        N = n;
        tree.resize(2 * n);
        //putting values in tree
        for (int i = 0; i < (int)nums.size(); i++)
            tree[n + i] = nums[i];

        //now making the tree
        for (int i = n - 1; i >= 1; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void update(int index, int val) {
        tree[index + N] = val;
        for (int i = (index + N) / 2; i >= 1; i = i / 2)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    ll segSum(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight) {
        if (queryLeft <= nodeLeft && nodeRight <= queryRight)
            return tree[node];
        if (nodeRight < queryLeft || queryRight < nodeLeft)
            return 0;

        int lastLeft = (nodeLeft + nodeRight) / 2;
        return segSum(2 * node, nodeLeft, lastLeft, queryLeft, queryRight) +
               segSum(2 * node + 1, lastLeft + 1, nodeRight, queryLeft, queryRight);
    }

    ll sumRange(int left, int right) {
        return segSum(1, 0, N - 1, left, right);
    }
};

int main() {
  int n,q;
  cin>>n>>q;
  vector<ll> a(n);
  for(int i=0;i<n;i++)
   cin>>a[i];

  NumArray obj(a);

  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int k,u;cin>>k>>u;
      //0 indexed array
      obj.update(k-1,u);
    }
    else{
      int left,right;cin>>left>>right;
      //0 indexed
      cout<< obj.sumRange(left-1,right-1)<<endl;
    }
  }
}