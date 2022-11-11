// Question Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

// Solution Details - https://leetcode.com/submissions/detail/446838592/

// SOLUTION - 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)return nums.size();
        int current = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1])current++;
            else current = 1;
            if(current == 3){
                nums.erase(nums.begin()+i);
                current--;
                i--;
            }
        }
        return nums.size();
    }
};
