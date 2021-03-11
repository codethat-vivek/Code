// Question Link - https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Solution Link - https://leetcode.com/submissions/detail/466512257/

// SOLUTION - 

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
    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;
        int lh = minDepth(root -> left);
        int rh = minDepth(root -> right);
        if(lh == 0 || rh == 0)
            return max(lh+1, rh+1);
        else{
            return lh < rh ? lh+1 : rh+1;
        }
    }
};
