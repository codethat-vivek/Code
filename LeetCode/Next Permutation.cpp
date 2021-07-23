// Question Link - https://leetcode.com/problems/next-permutation/

// Solution - 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos;
        int i;
        for(i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                pos = i-1;
                break;
            }
        }
        if (i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int anotherPos;
        for(int i=n-1; i>pos; i--){
            if(nums[i] > nums[pos]){
                anotherPos = i;
                break;
            }
        }
        swap(nums[pos], nums[anotherPos]);
        reverse(nums.begin()+pos+1, nums.end());
    }
};
