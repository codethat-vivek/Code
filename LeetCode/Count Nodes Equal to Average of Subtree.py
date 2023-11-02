# Question Link - https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

# Solution - 

class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        
        ans = 0
        def helper(node):
            if not node : return (0, 0)
            lnum, lsum = helper(node.left)
            rnum, rsum = helper(node.right)
            if (lsum+rsum+node.val)//(lnum+rnum+1) == node.val:
                nonlocal ans
                ans += 1
            return (lnum+rnum+1, lsum+rsum+node.val)
        
        helper(root)
        
        return ans
            
            
