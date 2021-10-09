# Question Link - https://leetcode.com/problems/keys-and-rooms/

# Solution - 

class Solution:
    def dfs(self, rooms, vis, roomNumber):
        vis[roomNumber] = True
        for room in rooms[roomNumber]:
            if not vis[room]:
                self.dfs(rooms, vis, room)

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        vis = [False for _ in range(len(rooms))]
        self.dfs(rooms, vis, 0)
        for each in vis:
            if each == False:
                return False
        return True
        
