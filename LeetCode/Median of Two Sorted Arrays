// Question Link - https://leetcode.com/problems/median-of-two-sorted-arrays/

// Solution Details - https://leetcode.com/submissions/detail/444001864/

// SOLUTION - 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        for(int k=i; k<nums1.size(); k++)
            ans.push_back(nums1[k]);
    
    
        for(int k=j; k<nums2.size(); k++)
            ans.push_back(nums2[k]);
        
        double median;
        if(ans.size() % 2 != 0)
            median = ans[(ans.size()-1)/2.0];
        else
            median = (ans[(ans.size()-1)/2] + ans[ans.size()/2] ) /2.0;
        
        return median;
        
    }
};
