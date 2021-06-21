// Question Link - https://www.codechef.com/problems/CHN15A

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n, k;
	while(t--){
	    cin >> n >> k;
	    int ele;
	    int cnt =0;
	    for(int i=0; i<n; i++){
	        cin >> ele;
	        if((ele+k)%7 == 0)
	            cnt++;
	    }
	    cout << cnt << endl;
	}
	return 0;
}
