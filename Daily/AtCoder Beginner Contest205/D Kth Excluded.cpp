// Question Link - https://atcoder.jp/contests/abc205/tasks/abc205_d

// Solution ( # COPIED ) - 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    
    ll n, q;
    cin >> n >> q;
    vector<ll>arr(n);
    for(ll i=0; i<n; i++)
      cin >> arr[i];

    vector<ll>c(n);
    for(int i=0; i<n; i++){
      c[i] = arr[i]-i-1;
      //cout<<c[i]<<" ";
    }
    //cout<<endl;

    for(ll i=0; i<q; i++){
      ll k;
      cin >> k;
      ll r = lower_bound(c.begin(), c.end(), k) - c.begin();
      ///cout<<"r = "<<r<<endl;
      ll ans;
      if(r == 0)
        ans = k;
      else
        ans = arr[r-1] + (k-c[r-1]); 
      cout << ans << endl;
    }


  return 0;
}
