// Question Link - https://codeforces.com/contest/1538/problem/C

// Solution - 

//CODEFORCES
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{	
	ll t;
	cin >> t;
	for(ll k =1; k<=t; k++){
		ll n, l, r;
		cin >> n >> l >> r;
		vector<ll> arr(n);
		for(ll i=0; i<n; i++)
			cin >> arr[i];
		
		ll ans = 0;
 
		sort(arr.begin(), arr.end());
		std::vector<ll>::iterator lower, higher;
		for(ll i=0; i<n-1; i++){
			lower = lower_bound(arr.begin()+i+1, arr.end(), l-arr[i]);
			higher = upper_bound(arr.begin()+i+1, arr.end(), r-arr[i]);
 
			ans += (higher-lower);
		}
		cout << ans << endl;
		
	}
 
}
