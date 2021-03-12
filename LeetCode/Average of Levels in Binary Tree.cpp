// Question Link - https://leetcode.com/problems/average-of-levels-in-binary-tree/

// Solution Link - https://leetcode.com/submissions/detail/466801223/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root == nullptr)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double l_sum = 0;
            for(int i=0; i<size; i++){
                TreeNode * n = q.front();
                l_sum += n -> val;
                q.pop();
                if(n -> left)q.push(n->left);
                if(n -> right)q.push(n->right);
            }
            double l_avg = l_sum*1.0/size;
            ans.push_back(l_avg);
        }
        return ans;
    }
};
