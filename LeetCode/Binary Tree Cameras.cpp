// Question Link - https://leetcode.com/problems/binary-tree-cameras/

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
    /*
     # There are two possibilities for any node -
        - It has a camera ================== (0)
        - It does not have a camera
            - If the node is covered by (it's child node) ========= (1)
            - If the node is not covered and needs one  =========== (-1)
    */
    
    int helper(TreeNode *root, int &camera){
        if(root == NULL)
            return 1;
        
        int leftPart = helper(root -> left, camera);
        int rightPart = helper(root -> right, camera);
        
        if(leftPart == -1 || rightPart == -1){
            camera++;
            return 0;
        }
        if(leftPart == 1 && rightPart == 1)
            return -1;
        
        return 1;
        
        
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        int x = helper(root, camera);
        if(x == -1)return 1 + camera;
        return camera;
    }
};
