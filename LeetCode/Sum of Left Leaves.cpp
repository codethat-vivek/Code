// Question Link - https://leetcode.com/problems/sum-of-left-leaves/

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
    void helper(TreeNode *root, int &sum, bool flag){
        if(root == NULL)return;
        if(flag && root -> left == NULL && root -> right == NULL)sum += root -> val;
        helper(root -> left, sum, true);
        helper(root -> right, sum, false);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, false);
        return sum;
    }
};
