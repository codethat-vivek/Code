// Question Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Solution - 

class Solution {
public:
    bool helper(TreeNode* root, int k, unordered_set<int>&us){
        if(root == NULL)
            return false;
        if(us.find(root -> val) != us.end())
            return true;
        else
            us.insert(k - root->val);
        bool lp = helper(root->left, k, us);
        bool rp = helper(root-> right, k, us);
        if(lp || rp)
            return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>us;
        return helper(root, k, us);
        
    }
};
