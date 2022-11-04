# Question Link - https://leetcode.com/problems/lru-cache/

# Solution - 

class DoublyLinkedList:
    def __init__(self, key, val, prev = None, next = None):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next

class LRUCache:
    
    # IMPORTANT INTERVIEW QUESTION
    
    def __init__(self, capacity: int):
        self.capacity = capacity
        # hashmap and doubly linked list
        self.hashmap = collections.defaultdict(DoublyLinkedList)
        self.head = DoublyLinkedList(-1, -1)
        self.tail = DoublyLinkedList(-1, -1)
        
        # making the links
        self.head.next = self.tail
        self.tail.prev = self.head

        
    def printDoublyLinkedList(self):
        temp = self.head.next
        while temp != self.tail:
            print(temp.key, temp.val)
            temp = temp.next
        
        
    def delete(self, node):
        p, n = node.prev, node.next
        p.next = n
        n.prev = p
    
    def addToHead(self, node):
        nn = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = nn
        nn.prev = node
            
    def get(self, key: int) -> int:
        ans = -1
        if key in self.hashmap:
            node = self.hashmap[key]
            ans = node.val
            # but now we will have to make this node our recent one
            self.delete(node)
            self.addToHead(node)
        return ans
            
        

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            node = self.hashmap[key]
            node.val = value
            self.delete(node)
            self.addToHead(node)
            return
        
        node = DoublyLinkedList(key, value)
        if self.capacity == len(self.hashmap):
            # first delete the recent node
            k = self.tail.prev.key
            self.delete(self.tail.prev)
            self.hashmap.pop(k)
            
            # now add node next to head and to the hashmap as well
            self.addToHead(node)
            self.hashmap[key] = node
        
            return
        
        
        self.addToHead(node)
        self.hashmap[key] = node



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
