/*
Question - Maximum Subarray Sum

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Example 1:
  Input:
  N = 5
  arr[] = {1,2,3,-2,5}
  Output:
  9
  Explanation:
  Max subarray sum is 9
  of elements (1, 2, 3, -2, 5) which 
  is a contiguous subarray.
*/

// SOLUTION - 

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int best = 0;
    int current_mx = 0;
    for(int i=0; i<n; i++){
        current_mx = max(arr[i], current_mx+arr[i]);
        best = max(best, current_mx);
    }
    return best;
}

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
