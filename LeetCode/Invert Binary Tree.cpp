// Question Link - https://leetcode.com/problems/invert-binary-tree/

// Solution - 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        TreeNode* lp = invertTree(root -> left);
        TreeNode* rp = invertTree(root -> right);
        root -> left = rp;
        root -> right = lp;
        return root;
    }
};
