# Question Link - https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        adj = collections.defaultdict(list)
        
        def travel(root):
            if not root : return
            if root.left :
                adj[root.val].append(root.left.val)
                adj[root.left.val].append(root.val)
            if root.right :
                adj[root.val].append(root.right.val)
                adj[root.right.val].append(root.val)
            travel(root.left)
            travel(root.right)
        
        travel(root)
        
        def bfs(node):
            q = collections.deque()
            q.append(node)
            st = set()
            ans = 0
            while q:
                size = len(q)
                while size:
                    size -= 1
                    ele = q.popleft()
                    st.add(ele)
                    for child in adj[ele]:
                        if child not in st:
                            q.append(child)
                ans += 1
            return ans
        
        
        return bfs(start)-1
