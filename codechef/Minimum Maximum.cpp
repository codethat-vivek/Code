// Question Link - https://www.codechef.com/problems/MNMX

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	long n;
	while(t--){
	    cin >> n;
	    long long int ele;
	    long long int mm = 100000;
	    for(long i=0; i<n; i++){
	        cin >> ele;
	        if(mm > ele)
	            mm = ele;
	    }
	    cout << mm*(n-1) << "\n";
	}
	return 0;
}
