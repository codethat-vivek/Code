/*
Find the pair of numbers from the given array that gives the minimum absolute difference between two numbers in the pair. 
Your task is to find the pairs which give the minimum absolute difference. There can be many possibilities. Print the minimum value pairs.

Input:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows:
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN respectively.

Output:
For each test case, print a pair of integers in increasing order.

*/

// Solution - 

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n;
	while(t--){
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin >> arr[i]; 
	   
	    sort(arr, arr+n); // 2 3 4 5
	    
	    int a=arr[0], b=arr[1], minDiff=abs(arr[0]-arr[1]);
	    
	    for(int i=0; i<n-1; i++){
	        if(minDiff > abs(arr[i] - arr[i+1])){
	            minDiff = abs(arr[i] - arr[i+1]);
	            a = arr[i];
	            b = arr[i+1];
	        }
	    }
	    
	    cout << min(a, b) << " " << max(a, b) << endl;
	}
	return 0;
}
