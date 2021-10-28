// Question Link - https://leetcode.com/problems/longest-mountain-in-array/

// Solution - 

class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int i, j;
        for(int k=1; k<n; k++){
            if(nums[k] > nums[k-1]){
                j = k+1;
                i = k-1;
                break;
            }  
        }
        bool inc = true;
        bool equal = false;
        int ans = 0;
        while(j < n){
            if(inc){
                if(nums[j] > nums[j-1]){
                    j += 1;
                    continue;
                }
                if(nums[j] < nums[j-1]){
                    inc = false;
                    ans = max(ans, j-i+1);
                    j += 1;
                    continue;
                }
                if(nums[j] == nums[j-1])
                    equal = true;        
            }
            else{
                if(nums[j] < nums[j-1]){
                    ans = max(ans, j-i+1);
                    j += 1;
                    continue;
                }
                if(nums[j] > nums[j-1]){
                    inc = true;
                    ans = max(ans, j-i);
                    i = j-1;
                    j += 1;
                    continue;
                }
                if(nums[j] == nums[j-1]){
                    ans = max(ans, j-i);
                    equal = true;
                    j += 1;
                }
            }
            if(equal){
                while(j < n && nums[j] <= nums[j-1])
                    j++;
                if(j == n)
                    return ans;
                equal = false;
                inc = true;
                i = j-1;
                j++;
            }
        }
        return ans;
    }
};
