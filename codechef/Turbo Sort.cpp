// Question Link - https://www.codechef.com/problems/TSORT

// Solution Link - https://www.codechef.com/viewsolution/31770497

// SOLUTION -

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
	    cin>>arr[i];
	}
	sort(arr, arr+n);
	for(int i=0; i<n; i++){
	    cout<<arr[i]<<endl;
	}
    
	
	return 0;
}
