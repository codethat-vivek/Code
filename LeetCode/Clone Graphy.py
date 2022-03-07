# Question Link - https://leetcode.com/problems/clone-graph/

# Solution - 

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node == None:
            return None
        
        dt = dict()
        visited = [False]*102
        
        def go(node):
            if node == None:
                return None
            
            root = Node(node.val)
            visited[root.val] = True
            dt[root.val] = root
            
            for each in node.neighbors:
                if each != None:
                    if visited[each.val] == False:
                        root.neighbors.append(go(each))
                    else:
                        root.neighbors.append(dt[each.val])
            
            return root

        return go(node)
        
