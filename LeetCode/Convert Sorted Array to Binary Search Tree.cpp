// Question Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Solution - 

class Solution {
public:
    TreeNode* helper(vector<int>nums, int low, int high){
        if(low > high)
            return NULL;
        int mid = (low+high)/2;
        // nums[mid] -> root
        TreeNode *node = new TreeNode(nums[mid]);
        node -> left = helper(nums, low, mid-1);
        node -> right = helper(nums, mid+1, high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
};
