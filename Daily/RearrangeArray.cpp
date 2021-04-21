/*
Question - Rearrange Array Alternatively
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively 
i.e first element should be max value, second should be min value, third should be second max, 
fourth should be second min and so on.

Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.
*/

// SOLUTION - 
 
#include <bits/stdc++.h>
using namespace std;

// This function wants you to modify the given input
// array and no need to return anything

void rearrange(long long *arr, int n) 
{ 
	
	// Your code here
	 vector<long long>ans;
	 long long i=0, j=n-1;
	 while(i<=j){
	     ans.push_back(arr[j--]);
	     ans.push_back(arr[i++]);
	 }
	 
	 
	 for(long long k=0; k<n; k++){
	     arr[k] = ans[k];
	 }
}

int main() 
{
    int t;
    
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        //calling rearrange() function
        rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
