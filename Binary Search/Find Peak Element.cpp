/*
FIND PEAK ELEMENT IN AN ARRAY:

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example :

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>arr, int low, int high, int n){
    int mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(mid == 0)
            return 1;
        if(mid == n-1)
            return n-2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;
        else if(arr[mid] < arr[mid+1])
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}

int findPeak(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)
        return 0;
    if(nums[0] > nums[1])
        return 0;
    if(nums[n-1] > nums[n-2])
        return n-1;
    return binarySearch(nums, 0, n-1, n);
}

int main()
{
    int n;
    cin >> n;
   
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int idx = findPeak(v);
    cout << idx << endl;
   
    return 0;
}
