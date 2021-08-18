// Question Link - https://www.codechef.com/problems/KTTABLE

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n;
	while(t--){
	    cin >> n;
	    int arr[n];
	    int cap[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    for(int i=0; i<n; i++)
	        cin >> cap[i];
	    int cnt = 0;
	    for(int i=0; i<n; i++){
	        if(i==0 && cap[i] <= arr[i])
	            cnt ++;
	        else if(arr[i] - arr[i-1] >= cap[i])
	            cnt ++;
	    }
	    cout << cnt << endl;
	    
	}
	return 0;
}
