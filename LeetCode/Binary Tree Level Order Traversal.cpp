// Question Link - https://leetcode.com/problems/binary-tree-level-order-traversal/

// Solution Link - https://leetcode.com/submissions/detail/466788399/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == nullptr)
            return v;
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>vec;
            while(size--){
                TreeNode* n = q.front();
                vec.push_back(n->val);
                q.pop();
                if(n -> left)q.push(n -> left);
                if(n -> right)q.push(n -> right);
            }
            v.push_back(vec);
        }
        return v;
    }
};
