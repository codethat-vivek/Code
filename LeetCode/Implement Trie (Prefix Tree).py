# Question Link - https://leetcode.com/problems/implement-trie-prefix-tree/

# Solution - 

class Node:
    def __init__(self, character, is_end = False):
        self.char = character
        self.children = dict()
        self.end = is_end

class Trie:

    def __init__(self):
        self.root = Node('$')

    def insert(self, word: str) -> None:
        self.curr = self.root
        for c in word:
            if c not in self.curr.children:
                self.curr.children[c] = Node(c)
            self.curr = self.curr.children[c]
        self.curr.end = True
                

    def search(self, word: str) -> bool:
        self.curr = self.root
        for c in word:
            if c not in self.curr.children:
                return False
            self.curr = self.curr.children[c]
        return self.curr.end

    def startsWith(self, prefix: str) -> bool:
        self.curr = self.root
        for c in prefix:
            if c not in self.curr.children:
                return False
            self.curr = self.curr.children[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
