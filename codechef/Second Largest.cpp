// Question Link - https://www.codechef.com/problems/FLOW017

// Solution Link - https://www.codechef.com/viewsolution/36453309

// SOLUTION - 

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int arr[3];
	    cin >> arr[0];
	    cin >> arr[1];
	    cin >> arr[2];
	    sort(arr, arr+3);
	    cout<<arr[1]<<endl;
	    
	}
	return 0;
}
