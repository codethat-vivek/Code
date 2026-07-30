# Question Link - https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/

# Solution - 

class Solution:
    def minimumDistance(self, word: str) -> int:
        n = len(word)
        def getPos(letter):
            return ((ord(letter) - ord('A')) // 6, (ord(letter) - ord('A')) % 6)
        
        def getDist(A, B):
            x, y = getPos(A), getPos(B)
            return abs(x[0] - y[0]) + abs(x[1] - y[1])

        # 300*26 = 7800 ---- OPTIMIZED
        # i - index of last character typed with one of my hands
        # other - last character typed by my other hand
        # we are considering word[i+1]
        @cache
        def optRecur(i, other):
            if i == n-1: return 0
            onehand = getDist(word[i], word[i+1]) + optRecur(i+1, other)
            if other == '': other = word[i+1]
            secondhand = getDist(other, word[i+1]) + optRecur(i+1, word[i])

            return min(onehand, secondhand)

        return min(optRecur(1, word[0]), getDist(word[0], word[1]) + optRecur(1, ''))
        
        #300*26*26 = 202800
        '''
        @cache
        def recur(i, leftlast, rightlast):
            if i == n:
                return 0
            
            lefthand, righthand = 0, 0
            
            #type with left
            lefthand += (getDist(leftlast, word[i]) + recur(i+1, word[i], rightlast))

            if rightlast == '':
                rightlast = word[i]

            #type with right
            righthand += (getDist(rightlast, word[i]) + recur(i+1, leftlast, word[i]))
            
            return min(lefthand, righthand)
        
        r1 = recur(2, word[0], word[1])
        r2 = recur(2, word[1], '') + getDist(word[0], word[1])

        return min(r1, r2)
        '''
