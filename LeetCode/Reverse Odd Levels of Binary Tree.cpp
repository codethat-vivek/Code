// Question Link - https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int len = (int)q.size();
            vector<TreeNode*> vt;
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                if(level % 2 == 1)
                    vt.push_back(node);
                if(node -> left)q.push(node -> left);
                if(node -> right) q.push(node -> right);
                
            }
            
            for(int i=0; i<vt.size()/2; i++)
                swap(vt[i] -> val, vt[vt.size()-i-1] -> val);
            vt.clear();
            level ++;
        }
        
        return root;
    }
};
