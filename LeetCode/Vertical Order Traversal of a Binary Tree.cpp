// Question Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Solution - 

class Solution {
public:
    map<int, vector<pair<int, int>>>memo; // here key will be column
    
    void pre(TreeNode* root, int row, int col){
        if(root == nullptr)
            return;
        memo[col].push_back(make_pair(row, root -> val));
        pre(root->left, row+1, col-1);
        pre(root->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        pre(root, 0, 0);
        for(auto x : memo){
            vector<pair<int, int>>vp = x.second;
            sort(vp.begin(), vp.end());
            vector<int>t;
            for(auto y : vp)
                t.push_back(y.second);
            ans.push_back(t);
        }
        return ans;
    }
};

/*
Random Trees for testing ->
[1, 2, 3, null, 5, 6, 7, null, 8, 9, null, 10, 11, 12, 4, 2, 2, 1, null, null, 1, 2, null, null, null, 3, null, null, null, null, 55, 45, 455, null, 44, null, 11]
[44]
[1, 2]
[1, null, 2]
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
[1, 2, 3, 4, 5, 6, 7, 8, 9, null, 1, 2, null, 3, 4, null, null, 5, null, null, 2, null, null, null, 1, null, 5, 2, null, 1, 1, null, null, null, 2, 3, null, 
null, 2, null, null, null, 3, null, 3, 1, 1, 1, 1, 1]
*/
