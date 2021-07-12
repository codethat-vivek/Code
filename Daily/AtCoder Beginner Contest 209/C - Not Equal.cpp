// Question Link - https://atcoder.jp/contests/abc209/tasks/abc209_c

// Solution - 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf = 1e9+7;

int main()
{
  ll n;
  cin >> n;
  vector<ll>v(n);
  for(ll i=0; i<n; i++){
   	cin >> v[i]; 
  }
  
  sort(v.begin(), v.end());
  
  ll ans = 1;
  for(ll i=0; i<n; i++){
   ans = (ans * (v[i]-i))%inf; 
  }
  cout << ans << "\n";
  
  return 0;
}
