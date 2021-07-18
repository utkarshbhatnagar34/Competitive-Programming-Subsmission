class Solution
{
public:
  int singleNonDuplicate(vector<int> &a)
  {
    int n = (int)a.size();
    if (n == 1)
      return a[0];

    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
      mid = l + (r - l) / 2;

      if (mid - 1 >= 0 && a[mid] == a[mid - 1])
      {
        if ((mid - l) % 2 == 0)
          r = mid - 2;
        else
          l = mid + 1;
      }
      else if (mid + 1 < n && a[mid] == a[mid + 1])
      {
        if ((mid - l) % 2 == 0)
          l = mid + 2;
        else
          r = mid - 1;
      }
      else
      {
        return a[mid];
      }
    }
    return a[mid];
  }
};

//if length of array is always odd which is either 3 or 7 or 15
/* so 
 let array be 1 2 2 

 1 1 2 3 3 4 4 5 5

 1 1 2 2 3 3 4 4 5

when mid-l or r-mid is even than it means that it will contain all the pairs
so move on the other half

when mid-l or r-mid is odd it means it contain the required element
*/