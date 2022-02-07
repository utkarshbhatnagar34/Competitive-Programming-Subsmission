#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void longestPrefixSuffix(vector<int> &a, string str) {
    if (str.size() <= 1) return;
    int i = 0, j = 1, n = str.length();
    while (j < n && i < j) {
        if (str[i] == str[j]) {
            a[j] = i + 1;
            i++; j++;
        }
        else {
            if (i == 0)
                j++;
            else {
                i = a[i - 1];
            }
        }
    }
}
int strStr(string haystack, string needle) {
    int n = needle.size();
    int len = haystack.size();
    if (n == 0) return 0;

    vector<int> a(n);
    longestPrefixSuffix(a, needle);
    int j = 0, i = 0;
    while (i < len) {
        if (haystack[i] == needle[j]) {
            i++; j++;
        }
        else if (j != 0) {
            j = a[j - 1];
        }
        else {
            i++;
        }
        if (j == n)
            break;
    }
    if (i == len && j != n)
        return -1;

    return i - n;
}

int main(){
  string txt,patt;cin>>txt>>patt;
  int idx=strStr(txt,patt);
  if(idx==-1)
    cout<<"not found"<<endl;
  else
    cout<<"found"<<" "<<idx<<endl;
}