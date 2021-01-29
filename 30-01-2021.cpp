/*
Question - Subarray with given sum
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N and S as input parameters and 
returns a list containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. 
The two indexes in the list should be according to 1-based indexing. If no such subarray is found, return -1. 

For Example: 
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.
*/

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int s){
    
    // Your code here
    int current_sum = 0;
    int a=0,b=0;
    while(a < n || b < n){
        if(current_sum < s)
            current_sum += arr[b++];
        else if(current_sum > s)
            current_sum -= arr[a++];
        else if(current_sum == s){
            vector<int>v;
            v.push_back(a+1);
            v.push_back(b);
            return v;
        }
    }
    if (current_sum == s)
    {
        vector<int>x;
        x.push_back(a+1);
        x.push_back(b);
        return x;
    }
    
    vector<int>w;
    w.push_back(-1);
    return w;
    
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  
