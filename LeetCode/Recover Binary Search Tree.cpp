// Question Link - https://leetcode.com/problems/recover-binary-search-tree/

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
    void inorder(TreeNode *root, vector<int>&v){
        if(root == NULL)return;
        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }
    
    void find(TreeNode *root, int first, int second){
        if(root == NULL)return;
        if(root -> val == first)
            root -> val = second;
        else if(root -> val == second)
            root -> val = first;
        find(root -> left, first, second);
        find(root -> right, first, second);
        
    }
    
    void recoverTree(TreeNode* root) {
        vector<int>v;
        inorder(root, v);
        // for(int i=0; i<v.size(); i++)
        //     cout << v[i] << " ";
        // cout << endl;
        int first, second;
        bool firstfound = false;
        for(int i=0; i<v.size()-1; i++){
            if(v[i] > v[i+1]){
                if(!firstfound){
                    first = v[i];
                    second = v[i+1];
                    firstfound = true;
                }
                else{
                    second = v[i+1];
                    break;
                }
            }
        }
        //cout << first << " " << second << endl;
        find(root, first, second);
        return;
        
    }
};
/*
[12,11,14,null,null,13, 32, null, null, 16, 20]
[8, 4, 12, 2, 11, 10, 14, 1, 3, 5, 7, 9, 6, 13, 15]
[4, 8, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15]
[8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 15, 13]
[8, 4, 12, 2, 6, 10, 14, 3, 1, 5, 7, 9, 11, 13, 15]
[8, 4, 12, 9, 6, 10, 14, 1, 3, 5, 7, 2, 11, 13, 15]
[7, 4, 12, 2, 6, 10, 14, 1, 3, 5, 8, 9, 11, 13, 15]
[8, 15, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 4]
*/
