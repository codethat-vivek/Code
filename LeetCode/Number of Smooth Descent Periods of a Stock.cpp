// Question Link - https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/

// Solution - 

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0, curr = 1;
        for(int i=0; i<n-1; i++){
            if(prices[i] == prices[i+1] + 1)
                curr++;
            else{
                ans += (long long)((curr * (curr + 1))/2);
                curr = 1;
            }
        }
        ans += (long long)((curr * (curr + 1))/2);
        return ans;
    }
};
