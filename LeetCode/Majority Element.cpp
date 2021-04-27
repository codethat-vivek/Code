// Question Link - https://leetcode.com/problems/majority-element/

// Solution Link - https://leetcode.com/submissions/detail/485703799/

// SOLUTION - O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>um;
        int n = nums.size();
        for (int i=0; i<n; i++){
            um[nums[i]] += 1;
        }
        for(auto const &x : um){
            if (x.second > n/2)
                return x.first;  
        }
        return -1;
    }
};

// Another approach could be sorting

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2]; // Since we know that majority element always exists
    }
};
*/
