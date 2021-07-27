/*
Question - Pythagorean Triplet
Given an array arr of N integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2, otherwise false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.

*/

// SOLUTION - 

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	bool isTriplet(int a, int b, int c){
	    return c*c == a*a + b*b;
	}
	bool checkTriplet(int arr[], int n) {
	    // code here
	    sort(arr, arr+n);
	    for(int i=0; i<n; i++){
	        for(int j=i+1; j<n; j++){
	            for(int k=j+1; k<n; k++){
	                if (isTriplet(arr[i], arr[j], arr[k]))
	                    return true;
	            }
	        }
	    }
	    return false;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
