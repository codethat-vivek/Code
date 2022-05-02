// Question Link - https://leetcode.com/problems/sort-array-by-parity/

// Solution - 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i < j){
            if(nums[i] % 2 == 1 && nums[j] % 2 == 0){
                swap(nums[i], nums[j]);
                i += 1;
                j -= 1;
            }
            else if(nums[i] % 2 == 1)
                j -= 1;
            else if(nums[j] % 2 == 0)
                i += 1;
            else{
                i += 1;
                j -= 1;
            }
        }
        return nums;
    }
};
