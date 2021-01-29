// Question Link - https://www.codechef.com/problems/COMM3

// Solution Link - https://www.codechef.com/viewsolution/36745800

// SOLUTION - 

#include <iostream>
#include <math.h>
using namespace std;

double distance(int a, int b, int c, int d){
    double ans;
    ans = sqrt((d-b)*(d-b) + (c-a)*(c-a));
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	int r;
	int arr[3][2];
	while(t--){
	    cin >> r;
	    for(int i=0; i<3; i++){
	        for(int j=0; j<2; j++){
	            cin >> arr[i][j];
	        }
	    }
	    double fs, st, ft;
	    fs = distance(arr[0][0], arr[0][1], arr[1][0], arr[1][1]);
	    st = distance(arr[1][0], arr[1][1], arr[2][0], arr[2][1]);
	    ft = distance(arr[0][0], arr[0][1], arr[2][0], arr[2][1]);
	    
	    if(fs > r && ft > r)
	        cout << "no" << "\n";
	    else if(fs > r && st > r)
	        cout << "no" << "\n";
	    else if(ft > r && st > r)
	        cout << "no" << "\n";
	    else 
	        cout << "yes" << "\n";
	}
	return 0;
}
