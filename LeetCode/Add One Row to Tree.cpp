// Question Link - https://leetcode.com/problems/add-one-row-to-tree/

// Solution - 

class Solution {
public:
    
    TreeNode* helper(TreeNode *root, int val, int depth, bool lp){
        if(depth == 0){
            TreeNode *temp = new TreeNode(val);
            if(lp)
                temp -> left = root;
            else
                temp -> right = root;
            return temp;
        }
        if(root == NULL)
            return root;
        root -> left = helper(root -> left, val, depth-1, true);
        root -> right = helper(root -> right, val, depth-1, false);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *ans = new TreeNode(val);
            ans -> left = root;
            return ans;
        }
        return helper(root, val, depth-1, true);
    }
};
