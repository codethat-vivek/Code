// Question Link - https://leetcode.com/problems/jump-game-ii/

// Solution Details - https://leetcode.com/submissions/detail/442993136/

// SOLUTION -

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int i=0;
        int n = nums.size();
        if(n==1)
            return 0;
        while(i < n){
            int x = nums[i];
            int mx = -1;
            int index;
            for(int j=i+1; j<i+1+x; j++){
                if(j == n-1){
                    ans += 1;
                    return ans;
                }
                if(mx < nums[j] + j){
                    mx = nums[j]+j;
                    index = j;
                }
            }
            i = index - 1;
            i++;
            ans ++;
        }
        return ans;
    }
};
