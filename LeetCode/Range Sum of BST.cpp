// Question Link - https://leetcode.com/problems/range-sum-of-bst/

// Solution - 

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        if(root -> val < low) return rangeSumBST(root -> right, low, high);
        if(root -> val > high) return rangeSumBST(root -> left, low, high);
        return root -> val + rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
    }
};
