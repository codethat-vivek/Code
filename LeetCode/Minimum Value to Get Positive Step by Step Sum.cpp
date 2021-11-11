// Question Link - https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

// Solution - 

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int t = max(1, 1-nums[0]), finalAns = t;
        for(int i=0; i<n; i++){
            t += nums[i];
            if(t < 1){
                finalAns += (1-t);
                t = 1;
            }
        }
        return finalAns;
        
    }
};
/*

[1, -40, -50]
1 -> [2, -38] -- fail so start with 1+(1-(-38))=40
40 -> [41, 1, -49]  -- fail so start with 40+(1-(-49))=90
90 -> [91, 51, 1]

*/
