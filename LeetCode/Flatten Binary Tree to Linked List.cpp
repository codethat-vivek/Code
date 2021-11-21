// Question Link - 

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
    void helper(TreeNode *root, vector<int>&v){
        if(root == NULL) return;
        v.push_back(root -> val);
        helper(root -> left, v);
        helper(root -> right, v);
    }
    // void print(TreeNode *root){
    //     cout << endl;
    //     while(root){
    //         cout << root -> val << " ";
    //         root = root -> right;
    //     }
    // }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        vector<int>v;
        helper(root, v);
        TreeNode *dummy = root;
        dummy -> left = nullptr;
        for(int i=1; i<v.size(); i++){
            TreeNode *temp = new TreeNode(v[i]);
            dummy -> right = temp;
            dummy = dummy -> right;
        }
        
    }
};
