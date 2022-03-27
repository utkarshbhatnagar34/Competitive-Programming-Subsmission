#include <bits/stdc++.h>
using namespace std;

typedef    long long ll;
typedef    long double lld;
typedef    unsigned long long ull;
typedef    pair<int, int> pii;

#define    all(v) (v).begin(),(v).end()
#define    sz(v) (int)(v).size()
#define    getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define    print(v) {for(auto i:v) cout<<i<<" ";cout<<endl;}
#define    endl    "\n"
#define    SPEED      ios_base::sync_with_stdio(0); cin.tie(0);
//const    lld pi = 3.14159265358979323846;
//#define  mod    1000000007
vector<string> arr;

void formation(int idx,string &s,string str){
  int n=s.size();
  if(idx==n){
    arr.push_back(str);return;
  }
  if(s[idx]=='?'){
    str+='0';
    formation(idx+1,s,str);
    str.pop_back();
    str+='1';
    formation(idx+1,s,str);
  }
  else{
    str+=s[idx];
    formation(idx+1,s,str);
  }
}
bool palindrome(string &s)
{
  int i=0,j=s.size()-1;
  while(i<=j){
    if(s[i]!=s[j]) return false;
    i++;j--;
  }
  return true;
}
bool valid(string &s){
  int n=s.size();
  for(int i=0;i+4<n;i++){
    int len=5;
    while(i+len-1<n){
      string str=s.substr(i,len);
      if(palindrome(str)) return 1;
      len++;
    }
  }
  return 0;
}
int main()
{
  SPEED;
  int t;
  int test = 0;
  cin >> t;
  while (t--) {
    test++;
    cout << "Case #" << test << ": ";
    arr.clear();
    int n;string s;
    cin>>n>>s;
    if(n<5){
      cout<<"IMPOSSIBLE\n";continue;
    }
    string str="";
    formation(0,s,str);
    bool flag=0;
    for(auto i:arr){
      if(valid(i)==0){
        flag=1;break;
      }
    }
    if(flag==1){
      cout<<"POSSIBLE\n";
    }
    else
      cout<<"IMPOSSIBLE\n";
  }
  return 0;
}

//str.substr(starting position, length);
