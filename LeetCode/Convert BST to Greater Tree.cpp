// Question Link - https://leetcode.com/problems/convert-bst-to-greater-tree/

// Solution - 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode *root, int &maximum){
        if(root == NULL)
            return NULL;
        
        root -> right = helper(root -> right, maximum);
        root -> val += maximum;
        if(root -> val - maximum < 0)
            maximum = min(maximum, root -> val);
        else
            maximum = max(maximum, root -> val);
        root -> left = helper(root -> left, maximum);
        
        return root;
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int maximum = 0;
        return helper(root, maximum);
    }
};
