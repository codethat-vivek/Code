// Question Link - 

// Solution - 

class Solution {
public:
    int sm = 0;
    void helper(TreeNode *root, bool parent, bool grandParent){
        if(root != NULL){
            if(grandParent)
                sm += root -> val;
            if(root -> val % 2 == 0){
                helper(root -> left, true, parent);
                helper(root -> right, true, parent);
            }
            else{
                helper(root -> left, false, parent);
                helper(root -> right, false, parent);
            }
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        helper(root, false, false);
        return sm;
    }
};
