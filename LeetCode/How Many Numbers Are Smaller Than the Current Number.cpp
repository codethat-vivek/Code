// Question Link - https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

// Solution - 

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        temp = nums;
        sort(temp.begin(), temp.end());

        vector<int>ans;
        
        for(int i=0; i<n; i++){
            int lb = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            ans.push_back(lb);
        }
        return ans;
    }
};
