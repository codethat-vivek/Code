# Question Link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

# Solution - 

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def helperSerialize(node):
            if not node:
                res.append('n')
                return
            res.append(str(node.val))
            helperSerialize(node.left)
            helperSerialize(node.right)
        res = []
        helperSerialize(root)
        return " ".join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.split(' ')
        def helperDeserialize():
            self.index += 1
            if data[self.index] == 'n': return None
            node = TreeNode(int(data[self.index]))
            node.left = helperDeserialize()
            node.right = helperDeserialize()
            return node
        self.index = -1
        return helperDeserialize()
      
      
