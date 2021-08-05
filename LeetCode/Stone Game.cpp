// Question Link - https://leetcode.com/problems/stone-game/

// Solution - 

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /*
        STATEMENT -> 
        There are an even number of piles arranged in a row,and 
        each pile has a positive integer number of stones piles[i].
        The objective of the game is to end with the most stones.  
        The total number of stones is odd, so there are no ties.
        */
        
        /*
        One thing to note here is that there are even number of piles, which means there is even pair of choosing between alex and lee, i.e. 
        every time alex chooses some pile of stone there is always  corresponding stone pile for lee. Also there can not be tie ever.
        So a STRATEGY alex can choose to win this game could be to choose every odd or even index stone piles because there will be no tie, and alex should always win.
        NOTE -> Alex can have all odd, even indices but not necessarily always follow this pattern.
                For example : [5,4,3,5] in this case alex will pick 5 &4 which is one on even index and one on odd index.
                Yes, Alex can choose from 0th and 1st index too.. But here we are thinking in this way that, Alex is intentionally choosing only even or odd indices 
                as she know the sum of stones at  even and odd indices and She is choosing even or odd indices where the sum is greater.
        THEREFORE, WE CAN ALWAYS RETURN TRUE.
        */
        return true;
    }
};
