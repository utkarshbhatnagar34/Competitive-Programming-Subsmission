#include<bits/stdc++.h>
using namespace std;
#define    print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}

int find_parent(int child, vector<int> &parent) {
  if(parent[child]<0) return -1;
  if (parent[child]==child) return child;

  int ansistor = find_parent(parent[child], parent);
  parent[child] = ansistor;
  return parent[child];
}
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;

    vector<pair<int, int>> unequal;
    bool flag = 1;

    //implementing disjointed set
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < k; i++) {
      string sa,sb,r;
      cin>>sa>>r>>sb;
  
      int a = stoi(sa), b = stoi(sb),R=1;
      if(r=="=") R=1;
      else R=0;

      if (R) {
        // if (parent[a] == -1 && parent[b] == -1) {
        //   parent[b] = a;
        //   parent[a]=a;
        // }
        // else if(parent[a]==-1){
        //   parent[a]=find_parent(b, parent);
        // }
        // else if(parent[b]==-1){
        //   //cout<<a<<" "<<parent[a]<<" "<<find_parent(a, parent)<<endl;
        //   parent[b]=find_parent(a, parent);
        // }
        // else{
        //   find_parent(a, parent);
        //   find_parent(b, parent);
        //   int ansistor=parent[a];
        //   parent[a]=b;
        //   parent[ansistor]=b;
        // }
      }
      else {
        unequal.push_back({a, b});
      }
    }
    
    for (auto i : unequal) {
      int a = i.first, b = i.second;
      cout<<a<<" "<<b<<endl;
      if (find_parent(a, parent) == find_parent(b, parent)) {
        flag = 0; break;
      }
    }
   // print(parent);
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}