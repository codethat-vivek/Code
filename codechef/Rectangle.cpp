// Question Link - https://www.codechef.com/problems/RECTANGL

// Solution Link - https://www.codechef.com/viewsolution/36787483

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int arr[4];
	    for(int i=0; i<4; i++)
	        cin >> arr[i];
	        
	    sort(arr, arr+4);
	    
	    if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
	        cout << "YES" << endl;
	    else{
    	    if(arr[0] != arr[1])
    	        cout << "NO" << endl;
    	    else{
    	        if(arr[1] == arr[2])
    	            cout << "NO" << endl;
    	        else{
    	            if(arr[2] != arr[3])
    	                cout << "NO" << endl;
    	            else
    	                cout << "YES" << endl;
    	        }
    	    }
	            
	    }
	    
	}
	return 0;
}
