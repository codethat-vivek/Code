// Question Link - https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

// Solution - 

class Solution {
public:
    
    TreeNode * helper(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == NULL)
            return NULL;
        if(original == target)
            return cloned;
        
        TreeNode* lp = NULL;
        TreeNode* rp = NULL;
        lp = helper(original -> left, cloned -> left, target);
        rp = helper(original -> right, cloned -> right, target);
        if(lp == NULL)
            return rp;
        if(rp == NULL)
            return lp;
        return NULL;
        
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return helper(original, cloned, target);
    }
};
