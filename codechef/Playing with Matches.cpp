// Question Link - https://www.codechef.com/problems/MATCHES

// Solution - 

#include <iostream>
using namespace std;

int noOfMatches(int d){
    if(d == 1)
        return 2;
    if(d == 4)
        return 4;
    if(d == 7)
        return 3;
    if(d == 8)
        return 7;
    if(d == 0 || d == 6 || d == 9)
        return 6;
    if(d == 2 || d == 3 || d == 5)
        return 5;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	int a, b;
	while(t--){
	    cin >> a >> b;
	    int answer = 0;
	    int c = a+b;
	    while(c!=0){
	        answer += noOfMatches(c%10);
	        c = c/10;
	    }
	    cout << answer << endl;
	}
	return 0;
}
