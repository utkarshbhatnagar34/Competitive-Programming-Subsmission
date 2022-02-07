#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a,int l,int r){
  if(l>r) return 0;
  /*op1 hai ki mai a[l] le rha hai p1  toh.. p2 ka paas 2 option hai ya toh a[l+1] ya a[r]

    agr p2 a[l+1] leta hai toh next p1 a[l+2] ya a[r] le skta hai
    agr p2 a[r] leta hai toh next ma p1 a[l+1] ya a[r-1] le skta hai*/
  
  /* we take minimum because p2 also plays optimaly so he makes a good choise also*/  
  int op1=a[l]+min(solve(a,l+2,r),solve(a,l+1,r-1));
  int op2=a[r]+min(solve(a,l+1,r-1),solve(a,l,r-2));//p2 choise is written inside the min(,)

  return max(op1,op2);/*we take maximum here because p1 choses at this point*/
}
int main(){
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  cout<<solve(a,0,n-1);
}