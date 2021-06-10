// Question Link - https://codeforces.com/contest/1538/problem/A

// Solution - 

//CODEFORCES

 // Very Bad Solution 
  // Can be solved very easily

#include <bits/stdc++.h>
using namespace std;
 
int main()
{	
	int t;
	cin >> t;
	for(int k =1; k<=t; k++){
		int n;
		cin >> n;
		vector<int> arr(n);
		//cout << "case " << k << " : ";
		int mn;
		int mx;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			if(arr[i] == 1)
				mn = i;
			if(arr[i] == n)
				mx = i;
		}
		string flow;
		//cout << mn << " " << mx << endl;
		if(mn+1 < n-mn){
			flow = "left";
		}
		else if(mn+1 > n-mn){
			flow = "right";
			
		}
		else if(mn+1 == n-mn){
			flow = "middle";
		}
 
		//cout <<flow << endl;
		
		if(mx+1 < n-mx && flow == "left"){
			cout << max(mn+1, mx+1) << endl;
		}
		else if(mx+1 < n-mx && flow == "right"){
			cout << min(min(mx+1+n-mn, max(mn+1, mx+1)), max(n-mn, n-mx)) << endl;
		}
		else if(mx+1 > n-mx && flow == "left"){
			cout << min((min(n-mx+mn+1, max(mn+1, mx+1))), max(n-mn, n-mx)) << endl;
		}
		else if(mx+1 > n-mx && flow == "right")
			cout << max(n-mn, n-mx) << endl;
		else if(flow == "middle"){
			//cout << "hey";
			cout << mn+1 << endl;
		}
		else if(mx+1 == n-mx)
			cout << mx+1 << endl;
 
	}
 
	return 0;
}
