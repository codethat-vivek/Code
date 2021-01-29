/*
Question - 
Write a program to find the rank of a 3x3 Matrix.

Input: The first line contains an integer 'T' denoting the total number of test cases. 
       Each test case consists of 3 lines and each line consists of 3 integers. 
       First 3 lines denotes a matrix of whose rank is to be determined.  

Output: Rank of the matrix is displayed in one line.

Example:

Input: 
2
10 20 10
-20 -30 10
30 50 0
2 4 3
1 0 9
9 6 8

Output:
2
3
*/

// SOLUTION -

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int arr[3][3];
	    for(int i=0; i<3; i++){
	        for(int j=0; j<3; j++){
	            cin >> arr[i][j];
	        }
	    }
	    
	    int det;
	    det = ( arr[0][0]*(arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2]) ) - ( arr[0][1]*(arr[1][0]*arr[2][2] - arr[2][0]*arr[1][2]) ) + ( arr[0][2]*(arr[1][0]*arr[2][1] - arr[2][0]*arr[1][1]) );  
	    if (det != 0)
	        cout << 3 << endl;
	    else{
	        int newDet1, newDet2, newDet3, newDet4;
	        newDet1 = arr[1][1]*arr[2][2] - arr[2][1]*arr[1][2];
	        newDet2 = arr[1][0]*arr[2][1] - arr[2][0]*arr[1][1];
	        newDet3 = arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1];
	        newDet4 = arr[0][1]*arr[1][2] - arr[1][1]*arr[0][2];
	        if(newDet1 != 0 || newDet2 != 0 || newDet3 != 0 || newDet4 != 0)
	            cout << 2 << endl;
	        else 
	            cout << 1 << endl;
	    }
	    
	}
	return 0;
}
