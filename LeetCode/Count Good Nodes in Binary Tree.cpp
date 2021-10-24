// Question Link - https://leetcode.com/problems/count-good-nodes-in-binary-tree/

// Solution - 

class Solution {
public:
    
    void helper(TreeNode *root, int mx, int &ans){
        if(root == NULL)
            return;
        if(root -> val >= mx)
        {
            mx = root -> val;
            cout << mx << " ";
            ans += 1;
        }
        helper(root->left, mx, ans);
        helper(root->right, mx, ans);
    }
    
    int goodNodes(TreeNode* root) {
        int mx = -100001;
        int ans = 0;
        helper(root, mx, ans);
        return ans;
    }
};
