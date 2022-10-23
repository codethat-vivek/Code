// Question Link - https://leetcode.com/problems/set-mismatch/

// Solution - 

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>hash(10001, 0), ans(2, 0);
        for(int i : nums){
            if(hash[i] == 1)
                ans[0] = i;
            else
                hash[i] = 1;
        }
        for(int i=1; i<hash.size(); i++){
            if(hash[i] == 0){
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};
