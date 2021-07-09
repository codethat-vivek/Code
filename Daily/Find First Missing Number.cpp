/*
Question - Given an array that consists of positive integers. Find the first integer that is missing in the given array.
Sample Input -
[2, 5, 1, 4]
Output -
3

Sample Input -
[4, 6, 1, 2, 54, 88, 3]
Output - 
5
*/

// Solution - 

#include <iostream>
using namespace std;

int main(){
    // remember this technique only works when the numbers are positive
    int arr[10] = {-99, 3, 2, 1, 4, 6, 5, 8, 91, 92}; 
      // also here -99 is added just to make the array's index start from 1
      // There is no use of -99 in the program, I am just using this to make the array 1-based index. Probably a bad way, but it works
      // you can clearly see there is no use of -99 in the whole process other than what has been already described above.
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] > n)
            continue;
        arr[abs(arr[i])] = -abs(arr[abs(arr[i])]);
    }
    for(int i=1; i<n; i++){
        if(arr[i] > 0){
            cout << i;
            return 0;
        }
    }
    return 0; 
}

/*
Nice Technique
*/

