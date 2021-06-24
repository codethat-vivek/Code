// Question Link - https://leetcode.com/problems/array-nesting/

// Solution - 

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        int ans = -1;
        for(int i=0; i<n; i++){
            int loops = 0;
            int idx = i;
            do{
                vis[i] = 1;
                i = nums[i];
                loops++;
                
            }while(vis[i] == 0);
            
            ans = max(ans, loops);
            i = idx;
            
        }
        return ans;
    }
};
