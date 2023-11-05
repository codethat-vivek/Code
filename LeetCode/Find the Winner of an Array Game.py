# Question Link - https://leetcode.com/problems/find-the-winner-of-an-array-game/

# Solution - 

class Node:
    def __init__(self, data):
        self.val = data
        self.next = None

class Solution:
    
    def getWinner(self, arr: List[int], k: int) -> int:
        n = len(arr)
        start = Node(-1)
        temp = start
        last = None
        for i in range(n):
            node = Node(arr[i])
            temp.next = node
            temp = node
            last = node
            
        
        temp = start.next
        temp1 = temp.next
        i = cnt = 0
        lastWinner = None
        while i < n:
            #print(i, temp.val, temp1.val, lastWinner, cnt)
            if temp.val > temp1.val:
                if lastWinner == None:
                    lastWinner = temp.val
                    cnt += 1
                    if cnt == k: return lastWinner
                elif temp.val == lastWinner:
                    cnt += 1
                    if cnt == k: return lastWinner
                else:
                    lastWinner = temp.val
                    cnt = 1
                # move temp1 to last
                temp.next = temp1.next
                last.next = temp1
                temp1 = temp.next
            else:
                if lastWinner == None:
                    lastWinner = temp1.val
                    cnt += 1
                    if cnt == k:
                        return lastWinner
                elif temp1.val == lastWinner:
                    cnt += 1
                    if cnt == k:
                        return lastWinner
                else:
                    lastWinner = temp1.val
                    cnt = 1
                # move temp to last
                start.next = temp.next
                last.next = temp
                temp = temp1
                temp1 = temp.next
            last = last.next
            i += 1
            
        
        return max(arr)
