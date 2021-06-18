// Question Link - https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *r = new TreeNode(val);
            return r;
        }
        if(root -> left == NULL && root -> right == NULL){
            TreeNode *r = new TreeNode(val);
            if(root -> val < val)
                root -> right = r;
            else
                root -> left = r;
            return root; 
        }
        if(root -> val < val){
            TreeNode *r = insertIntoBST(root -> right, val);
            root -> right = r;
            return root;
        }
        if(root -> val > val){
            TreeNode *r = insertIntoBST(root -> left, val);
            root -> left = r;
            return root;
        }
        return root;
    }
};
