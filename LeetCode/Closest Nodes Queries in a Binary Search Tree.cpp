// Question Link - https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/

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
    vector<int>arr;
    void f(TreeNode *root){
        if(root == NULL) return;
        f(root -> left);
        arr.push_back(root -> val);
        f(root -> right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        f(root);
        vector<vector<int>> ans;
        int idx;
        for(int q : queries){
            idx = lower_bound(arr.begin(), arr.end(), q)-arr.begin();
            if(idx == arr.size()) ans.push_back({arr[idx-1], -1});
            else if(arr[idx] == q) ans.push_back({q, q});
            else if(idx == 0)ans.push_back({-1, arr[idx]});
            else ans.push_back({arr[idx-1], arr[idx]});
        }
        return ans;
    }
};
