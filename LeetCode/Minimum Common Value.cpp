// Question Link - https://leetcode.com/problems/minimum-common-value/

// Solution - 

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return -1;
    }
};
