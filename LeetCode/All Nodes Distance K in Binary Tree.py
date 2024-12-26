# Question Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

# Solution - 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        if k == 0: return [target.val]
        if not root.left and not root.right: return []
        adj = collections.defaultdict(list)
        q = collections.deque()
        q.append(root)
        
        while len(q) > 0:
            size = len(q)
            while size:
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                    adj[node.val].append(node.left.val)
                    adj[node.left.val].append(node.val)
                if node.right:
                    q.append(node.right)
                    adj[node.val].append(node.right.val)
                    adj[node.right.val].append(node.val)
                size -= 1
        
        ans = []
        #print(adj)
        q.append(target.val)
        vis = [0]*len(adj)
        vis[target.val] = 1
        while len(q) > 0:
            size = len(q)
            while size:
                node = q.popleft()
                size -= 1
                for child in adj[node]:
                    if not vis[child]:
                        if k == 1: ans.append(child)
                        vis[child] = 1
                        q.append(child)
            k -= 1
            if k == 0:
                return ans
        
        return ans
                
