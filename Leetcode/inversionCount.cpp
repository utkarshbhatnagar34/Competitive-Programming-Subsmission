#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll conquer(ll l, ll mid, ll r, vector<ll> &arr) {
    ll mergeInversion = 0;
    vector<int> result(r - l + 1);

    int i = 0, j = mid + 1, n = mid, m = r , k = 0;

    while (i <= n && j <= m) {
        if (arr[i] <= arr[j]) {
            mergeInversion += (j - (mid + 1));
            result[k++] = arr[i++];
        }
        else {
            result[k++] = arr[j++];
        }
    }
    while (i <= n) {
        mergeInversion += r-mid;
        result[k++] = arr[i++];
    }
    while (j <= m) {
        result[k++] = arr[j++];
    }
    for (int i = 0; i < r - l + 1; i++) arr[i] = result[i];
    return mergeInversion;
}
ll divide(ll l, ll r, vector<ll> &v) {
    if (l >= r)
        return 0;
    ll mid = l + (r - l) / 2;
    cout<<l<<" "<<mid<<" "<<r<<endl;
    ll leftInversion =  divide(l, mid, v);
    ll rightInversion = divide(mid + 1, r, v);
    ll mergeInversion = conquer(l,mid, r, v);
    cout<<l<<" "<<r<<" "<<leftInversion<<" "<<rightInversion<<" "<<mergeInversion<<endl;
    return mergeInversion + leftInversion + rightInversion;
}
long long int inversionCount(long long arr[], long long N)
{
    vector<ll> v(N);
    for (ll i = 0; i < N; i++) v[i] = arr[i];

    return divide(0, N - 1, v);
}


int main(void) {
  ll N;
  cin>>N;
  ll arr[N];
  for(ll i=0;i<N;i++) {
    cin>>arr[i];
  }

  cout<<inversionCount(arr,N);
}