// Question Link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// Solution Link - https://leetcode.com/submissions/detail/466804912/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)return ans;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>v;
            for(int i=0; i<size; i++){
                TreeNode * n = q.front();
                v.push_back(n -> val);
                q.pop();
                if(n -> left) q.push(n -> left);
                if(n -> right) q.push(n -> right);    
            }
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
