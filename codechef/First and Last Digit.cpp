// Question Link - https://www.codechef.com/problems/FLOW004

// Solution Link - https://www.codechef.com/viewsolution/31771091

// SOLUTION -

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int a = n%10;
	    int b;
	    while(n > 0){
	        b = n%10;
	        n = n/10;
	    }
	    cout<<a+b<<endl;
	}
	
	return 0;
}
