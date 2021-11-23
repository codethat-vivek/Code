# Question Link - https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:            
    def findNums(self, traversal):
        from re import findall
        return list(map(int, findall(r'\d+', traversal)))
    def findDashes(self, traversal):
        dashes, cnt = [0], 0
        for i in traversal:
            if i == "-":
                cnt += 1
            else:
                if cnt != 0:dashes.append(cnt)
                cnt = 0
        return dashes
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        nums = self.findNums(traversal) # all the node.val's
        dashes = self.findDashes(traversal)
        #print(nums, dashes)
        # we will push (node, node.level)
        i, stack, n = 0, [], len(nums)
        ans = TreeNode(-1)
        curr = ans
        while i < n:
            node = TreeNode(nums[i])
            level = dashes[i]
            if len(stack) == 0 or level > stack[-1][1]:
                curr.left = node
            else:
                while len(stack) != 0 and level <= stack[-1][1]:
                    stack.pop()
                stack[-1][0].right = node
                
            stack.append((node, level))
            curr = node
            i += 1
        
        return ans.left
