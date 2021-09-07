// Question Link - https://leetcode.com/problems/merge-sorted-array/

// Solution - 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            for(int i=0; i<n; i++)
                nums1[i] = nums2[i];
            return;
        }
        if(n == 0)
            return;
        
        vector<int>v;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j])
                v.push_back(nums1[i++]);
            else
                v.push_back(nums2[j++]);
        }
        while(i<m)
            v.push_back(nums1[i++]);
        while(j<n)
            v.push_back(nums2[j++]);
        
        for(int i=0; i<m+n; i++)
            nums1[i] = v[i];
        
        
    }
};
