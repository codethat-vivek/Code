// Question Link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Solution - 

class Solution {
public:
    void helper(TreeNode* root, int &sm){
        if(root == NULL)
            return;
        helper(root -> right, sm);
        sm += root -> val;
        root -> val = sm;
        helper(root -> left, sm);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sm = 0;
        helper(root, sm);
        return root;
    }
};
