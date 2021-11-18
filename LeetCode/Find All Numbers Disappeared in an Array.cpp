// Question Link - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Solution - 

class Solution {
public:
  /*
  For each value in the array mark its presence by making the number negative at that place in array eg. if you have array [3,1,4,1] 
  for 3, i will go to index 2 and make its value negative ie. now nums[2] becomes -4. present array: [3,1,-4,1]
  for 1, i will go to index 0 and make its value negative ie. now nums[0] becomes -3. present array: [-3,1,-4,1]
  for 4, (take abs value), i will go to index 3 and make its value negative ie. now nums[3] becomes -1. present array: [-3,1,-4,-1]
  for 1 take abs value), i will go to index 0 as it is already -ve do nothing. present array: [-3,1,-4,-1]
  At last I will have [-3,1,-4,-1]. now i will iterate over the array, now whichever idx has positive value that number will not be in the array so as we have 
  nums[1]>0 so 2 is not in the list.
  */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx;
        for(int i=0; i<nums.size(); i++){
            idx = abs(nums[i])-1;
            nums[idx] = -abs(nums[idx]);
        }
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)
                ans.push_back(i+1);
        }
        return ans;
    }
};
