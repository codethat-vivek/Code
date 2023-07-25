# Question Link - https://leetcode.com/problems/peak-index-in-a-mountain-array/

# Solution - 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {   
        
        int n = arr.size(), i=0, j=n-1;
        while(i < j){
            if(j-i+1 == 3)
                return i+1;
            int mid = i + (j-i)/2;
            cout << mid << " " << i << " " << j << endl;
            if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
                i = mid;
            else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1])
                j = mid;
            else
                return mid;
        }
        
        return n;
    }
};
