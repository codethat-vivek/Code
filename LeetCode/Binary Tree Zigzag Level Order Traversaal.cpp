// Question Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Solution - 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        bool lr = true;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans;
    
        while(!q.empty()){
            int len = (int)q.size();
            vector<int>level;
            while(len--){
                level.push_back(q.front() -> val);
                TreeNode *t = q.front();
                q.pop();          
                if(t -> left)q.push(t -> left);
                if(t -> right)q.push(t -> right);
  
            }
            if(lr)
                ans.push_back(level);
            else{
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            lr = lr ^ 1;
        }
        
        return ans;
    }
};
