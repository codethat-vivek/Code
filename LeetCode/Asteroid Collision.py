# Question Link - https://leetcode.com/problems/asteroid-collision/

# Solution - 

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st = [asteroids[0]]
        n = len(asteroids)
        for i in range(1, n):
            if len(st) == 0:
                st.append(asteroids[i])
            # collision occurs
            elif len(st) != 0 and st[-1] > 0 and asteroids[i] < 0:
                if st[-1] == abs(asteroids[i]):
                    st.pop()
                elif st[-1] > abs(asteroids[i]):
                    continue
                else:
                    while len(st) != 0 and st[-1] > 0 and st[-1] < abs(asteroids[i]):
                        st.pop()
                    if len(st) != 0 and st[-1] == abs(asteroids[i]) :
                        st.pop()
                        continue
                    if len(st) == 0 or st[-1] < 0:
                        st.append(asteroids[i])
            else:
                st.append(asteroids[i])
        
        return st
                        
                    
