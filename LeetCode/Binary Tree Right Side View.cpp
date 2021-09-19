// Question Link - https://leetcode.com/problems/binary-tree-right-side-view/

// Solution - 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int len = (int)q.size();
            vector<int>temp;
            while(len--){
                TreeNode *t = q.front();
                temp.push_back(t -> val);
                q.pop();
                if(t -> left)q.push(t -> left);
                if(t -> right)q.push(t -> right);
            }
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};
