// Question Link - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Solution - 

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), x;
        for(int i=0; i<n; i++){
            x = i;
            do{
                if(nums[x] > nums[(x+1)%n])
                    break;
                x = (x+1)%n;
            }while(x != (i+n-1)%n);
            if(x == (i+n-1)%n)
                return true;
        }
        return false;
    }
};
