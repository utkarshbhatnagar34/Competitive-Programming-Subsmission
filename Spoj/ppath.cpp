#include<bits/stdc++.h>
using namespace std;


int main(){
  map<int,priority_queue<int>> mp;
  mp[1].push(2);mp[1].push(3);mp[1].push(4);
  while(mp[1].size()){
    cout<<mp[1].top()<<endl;mp[1].pop();
  }
}