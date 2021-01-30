/*
  Question - Count the Triplets
  Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
  Example 1:
    Input:
    N = 4
    arr[] = {1, 5, 3, 2}
    Output: 2
    Explanation: There are 2 triplets: 
    1 + 2 = 3 and 3 +2 = 5 
*/

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    int ans = 0;
	    if(n < 3)return 0;
	    sort(arr, arr+n);
	    for(int i=0; i<n-2; i++){
	        for(int j=i+1; j<n-1; j++){
	            for(int k=j+1; k<n; k++){
	                if(arr[i]+arr[j] == arr[k]){
	                    ans++;
	                    break;
	                }
	            }
	        }
	    }
	    return ans;
	}
};

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
} // Above solution is in O(n^3) complexity. Though it can be done in O(n^2) complexity.
