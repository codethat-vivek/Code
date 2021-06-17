// Question Link - https://leetcode.com/problems/jump-game/

// Solution - 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        if(nums[0] == 0)
            return false;
        int i=0;
        int x=0;
        do{
            x = max(x, i+nums[i]);
            if(x >= n-1)
                return true;
            i++;
            
        }while(i <= x);
        
        return false;
        
    }
};
