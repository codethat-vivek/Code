// Question Link - https://www.codechef.com/problems/POTATOES

// Solution Link - https://www.codechef.com/viewsolution/36767575

// SOLUTION - 

#include <iostream>
#include <math.h>
using namespace std;

int IsPrime(int n){
    
    for(int i=2; i<=int(sqrt(n)); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	int a, b;
	while(t--){
	    cin >> a >> b;
	    int i = a+b;
	    int j = 1;
	    bool flag = false;
	    while(flag == false){
	        if(IsPrime(i+j) == true){
	            flag = true;
	            break;
	        }
	        
	        j += 1;
	    }
	    
	    cout << j << "\n";
	    
	}
	return 0;
	
}
