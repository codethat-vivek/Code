// Question Link - https://leetcode.com/problems/number-of-distinct-averages/

// Solution - 

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        set<double>st;
        while(i < j)
            st.insert((nums[i++]+nums[j--])/2.0);
        return (int)st.size();
    }
};
