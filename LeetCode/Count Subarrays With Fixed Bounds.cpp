// Question Link - https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

// Solution - 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0, cnt = 0;
        int i=0, j=0;
        int mn=INT_MAX, mx=-1;
        int cntMn=0, cntMx=0;
        
        while(j < n){
            mn = min(mn, nums[j]);
            mx = max(mx, nums[j]);
            if(nums[j] == minK) cntMn++;
            if(nums[j] == maxK) cntMx++;
            
            if(mn < minK || mx > maxK){
                mn=INT_MAX; mx=-1;
                cnt = 0;
                cntMn=0; cntMx=0;
                j++;
                i = j;
                continue;
            }
            else if(mn == minK && mx == maxK){
                if(cnt == 0) cnt = 1;
                ans += cnt;
                int x = 0;
                while(cntMn >= 1 && cntMx >= 1){
                    if(nums[i] == minK) cntMn--;
                    else if(nums[i] == maxK) cntMx--;
                    i++;
                    x++;
                }
                if(x){
                    i--;
                    if(nums[i] == minK) cntMn++;
                    else if(nums[i] == maxK) cntMx++;
                    x--;
                }
                cnt += x;
                ans += x;
                //cout << i << " " << j << " " << x << " " << cnt << " " << ans << endl;
            }
            j++;
        }
        
        return ans;
        
    }
};
