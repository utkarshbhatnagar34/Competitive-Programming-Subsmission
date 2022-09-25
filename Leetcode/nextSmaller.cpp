#include<bits/stdc++.h>
using namespace std;

vector<int> help_classmate(vector<int> arr, int N)
{
  vector<int> ans(N, -1);
  // create a monotonic stack in descending order
  stack<int> st;

  for (int i = N - 1; i >= 0; i--)
  {
    while (st.size() && st.top() >= arr[i])
      st.pop();

   // cout << arr[i] << " " << st.size() << endl;
    if (st.size())
      ans[i] = st.top();

    st.push(arr[i]);
  }
  return ans;
}

int main() {
  int N;
  cin>>N;
  vector<int> arr(N);
  for(int i = 0; i < N; i++) {
    cin>>arr[i];
  }

  vector<int> ans = help_classmate(arr, N);

  for(auto &i: ans)
    cout<< i << " ";
}