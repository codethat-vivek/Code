// Question Link - https://leetcode.com/problems/find-bottom-left-tree-value/

// Solution - 

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // bfs
        queue<TreeNode*>q;
        q.push(root);
        vector<long>v;
        while(!q.empty()){
            TreeNode *get = q.front();
            int len = q.size();
            v.clear();
            while(len--){
                if(get -> left)q.push(get -> left);
                if(get -> right)q.push(get -> right);
                q.pop();
                v.push_back(get -> val);
                get = q.front();
            }
            
        }
        
        return v[0];
    }
};
