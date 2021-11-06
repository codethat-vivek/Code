// Question Link - https://leetcode.com/problems/single-number-ii/

// Solution - 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0, cnt=0;
        for(int i=0; i<32; i++){
            cnt = 0;
            int x = (1 << i);
            for(int ele : nums){
                if(ele & x)
                    cnt ++;
            }
            if(cnt % 3 == 1)
                ans |= x;
        }
        return ans;
    }
};
