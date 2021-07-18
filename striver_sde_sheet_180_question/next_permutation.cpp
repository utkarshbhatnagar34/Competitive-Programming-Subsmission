#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
#define endl "\n"
#define FIO                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
//const lld pi = 3.14159265358979323846;
//#define mod    1000000009

class Solution
{
public:
  void next_greater(vector<int> &a, int i)
  {
    //O(n)
    reverse(a.begin() + i + 1, a.end());
    swap(a[i], a[i + 1]);
  }
  void change(vector<int> &a, int i)
  {
    int k = a[i - 1];
    //using binary search time is log(n)
    int low = i, high = a.size() - 1;
    int idx = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (a[mid] <= k)
      {
        low = mid + 1;
      }
      else
      {
        idx = mid;
        high = mid - 1;
      }
    }
    if (idx == -1)
      idx = a.size() - 1;
    swap(a[idx], a[i - 1]);
  }
  void nextPermutation(vector<int> &a)
  {
    int n = a.size();
    int smallest = INT_MAX, biggest = 0, sm_idx = -1, big_idx = -1;
    bool fir = 0;
    int len = 0;
    for (int i = n - 1; i > 0; i--)
    {
      if (a[i - 1] >= a[i])
      {
        if (fir == 0)
        {
          fir = 1;
          smallest = INT_MAX;
          biggest = 0;
          sm_idx = -1, big_idx = -1;
          len = 0;
        }
        len++;
        if (a[i] < smallest)
        {
          smallest = a[i];
          sm_idx = i;
        }
        if (a[i] > biggest)
        {
          biggest = a[i];
          big_idx = i;
        }
        //when all in increasing order
        if (i == 1 && len == n - 1)
        {
          sort(a.begin(), a.end());
          break;
        }
      }
      else
      {
        if (fir == 1)
        {
          if (a[i] >= biggest)
          {
            reverse(a.begin() + i, a.end());
            change(a, i);
          }
          else
          {
            next_greater(a, i);
          }
          fir = 0;
          break;
        }
        else
        {
          swap(a[i], a[i - 1]);
          break;
        }
      }
    }
  }
};
int main()
{
  FIO;
  cout << "done";
  return 0;
}