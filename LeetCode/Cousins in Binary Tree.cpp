// Question Link - https://leetcode.com/problems/cousins-in-binary-tree/

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

vector<TreeNode*>parents;
vector<int>depths;

class Solution {
public:
    void dfs(TreeNode *root, int x, int y, TreeNode *parent, int depth){
        if(root == NULL) return;
        if(root -> val == x || root -> val == y){
            parents.push_back(parent);
            depths.push_back(depth);
        }
        dfs(root -> left, x, y, root, depth+1);
        dfs(root -> right, x, y, root, depth+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root -> val == x || root -> val == y) return false;
        parents.clear();
        depths.clear();
        dfs(root, x, y, NULL, 0);
        
        // cout << parents[0]  << " " << parents[1] << endl;
        // cout << depths[0] << " " << depths[1] << endl;
        
        if(parents[0] == parents[1]) return false;
        if(depths[0] != depths[1]) return false;
        return true;
    }
};
