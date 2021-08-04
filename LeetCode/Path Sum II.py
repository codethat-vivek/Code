# Question Link - https://leetcode.com/problems/path-sum-ii/

# Solution - 

class Solution:
    def helper(self, root, target):
        if root == None:
            return [False, []]
        target -= root.val
        ans = []
        if target == 0 and root.left == None and root.right == None:
            return [True, [[root.val]]]
        left_tf, left_p = self.helper(root.left, target)
        right_tf, right_p = self.helper(root.right, target)
        
        if left_tf == True:
            for each in left_p:
                each.append(root.val)
                ans.append(each)
        if right_tf == True:
            for each in right_p:
                each.append(root.val)
                ans.append(each)
        # both left and right parts are return false, i.e. there is no valid answer
        if not left_tf and not right_tf:
            return [False, []]
        return [True, ans]
  
    
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        a, ans =  self.helper(root, targetSum)
        print(ans)
        finalans = []    
        for each in ans:
            finalans.append(each[::-1])
        return finalans
