// Question Link - https://leetcode.com/problems/3sum-closest/

// Solution - 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = 100001;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int finalI, finalJ, finalK;
        for(int i=0; i<n-2; i++){
            int j=i+1;
            int k=n-1;
            while(j < k){
                int sm = nums[i]+nums[j]+nums[k];
                if(abs(sm-target) < diff){
                    finalI = i;
                    finalJ = j;
                    finalK = k;
                    diff = abs(sm-target);
                }
                if(sm > target)
                    k--;
                else
                    j++;
            }
        }
        return nums[finalI] + nums[finalJ] + nums[finalK];
    }
};
