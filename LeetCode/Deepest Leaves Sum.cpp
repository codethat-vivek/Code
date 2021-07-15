// Question Link - https://leetcode.com/problems/deepest-leaves-sum/

// Solution - 

class Solution {
public:
    int height(TreeNode * root){
        if(root == NULL)
            return 0;
        int lh = 0;
        int rh = 0;
        if(root -> left)
            lh = height(root -> left);
        
        if(root -> right)
            rh = height(root -> right);
        
        return max(lh, rh) + 1;
        
    }
    
    int helper(TreeNode *root, int h){
        int ans = 0;
        if(h == 1){
            ans += root -> val;
            return ans;
        }
        if(root -> left)
            ans += helper(root -> left, h-1);
        if(root -> right)
            ans += helper(root -> right, h-1);
        
        return ans;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        return helper(root, h);   
    }
};
