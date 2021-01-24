// Question Link - https://www.codechef.com/problems/SMPAIR

// Solution Link - https://www.codechef.com/viewsolution/36702824

// SOLUTION - 

#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; 
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector <int> v;
	    int ele;
	    for(int i=0; i<n; i++){
	        cin >> ele;
	        v.push_back(ele);
	    }
	    
	    sort(v.begin(), v.end());
	    cout << v[0] + v[1] << "\n";
	}
	return 0;
}
