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

//https://www.youtube.com/watch?v=AelfmnOnCRw(agga xor )
//test 15 2 2
//test  3 3 3 0
//test 2 2 2
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
  freopen("output.in", "w", stdout);
#endif
  FIO;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      xr = xr ^ a[i];
    }
    //if their are 2 elements left in the end than xor of all the element is zero thing!
    if (xr == 0)
    {
      cout << "YES";
    }
    else
    {
      /* X=xor of all the elements ,if array is following the condition than
      array can be broken down into different parts , with each part whose xor is X and
       a b....e|f g...n
       a^b^..^e=>X  and f^g^...^n=>X 
       */
      int k = 0;
      int X = 0;

      while (X != xr && k < n)
      {
        X = X ^ a[k];
        k++;
      }
      //cout << xr << " " << k << " " << X << endl;
      if (k == n)
      {
        cout << "NO";
      }
      else
      {
        int xr_of_remaing = 0;
        bool flag = 0;
        //since we can select only adjacent elements so it will work
        for (int i = k; i < n; i++)
        {
          xr_of_remaing = xr_of_remaing ^ a[i];
          if (xr_of_remaing == X)
          {
            xr_of_remaing = 0;
            flag = true;
          }
        }
        //xr_of_remaing==0 as in the end xor of elements should equal to X and if condition will become true and xr_of_remaning=0
        if (flag == 1 && xr_of_remaing == 0)
          cout << "YES";
        else
          cout << "NO";
      }
    }
    cout << endl;
  }
  return 0;
}

/*
the point is that if we have either 2 equal or 3 equal
2^2=0
2^2^2=2

2 remaining
2 2 :further xor 2^2=0 but we dont do it here
2 2 2 2: =>2,2|2,2=>xor of partition is 2 so=>2,2
2,2,2,2,2,2: it can be partioned into=>2,2,2|2,2,2=> 2,2

so when in the end 2 is remaining than it will always be further reduced to 0

3 remaining
2 2 2:=>2 |2 2=>2|0
2 2 2 2 2:=>2 2 2|2  2=>2 2 2

when 3 is remaining it means that xor of all the elements will be 2 in the end
or we can say that  2 2 2 
ex:
2 2 2 2 2
2^2^2^2^2=>2
so
2 2 2|2 2=>2|2 2

means all remaing case always be reduced to either one of the above case
*/