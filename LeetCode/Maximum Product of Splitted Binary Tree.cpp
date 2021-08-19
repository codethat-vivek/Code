// Question Link - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    long long inf = 1e9+7;
    long long findSum(TreeNode *root){
        if(root == NULL)
            return 0;
        long long lp = findSum(root -> left);
        long long rp = findSum(root -> right);
        return lp + rp + root -> val;
    }
    
    long long helper(TreeNode *root, long long total, long long &best){
        if(root == NULL)
            return 0;
        long long subtree = root -> val + helper(root -> left, total, best) + helper(root -> right, total, best);
        best = max(best, subtree*(total-subtree));
        return subtree;
    }
    
    int maxProduct(TreeNode* root) {
        
        long long best = INT_MIN;
        long long total = findSum(root);
        helper(root, total, best);
        int ans = best%inf;
        return ans;
    }
};
