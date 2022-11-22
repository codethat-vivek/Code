// Question Link - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

// Solution - 

class Solution {
public:
    
    int helper(vector<int>&bloomDay, int k, int days){
        int n = bloomDay.size(), bouquets = 0;
        int cnt = 0, i = 0;
        while(i < n){
            if(bloomDay[i] > days){
                i++;
                continue;
            }
            while(i < n && bloomDay[i++] <= days){
                cnt += 1;
                if(cnt%k == 0) bouquets++;
            }
            if(i != n)
                cnt = 0;
            
        }
        return bouquets;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long) m*k > (long)bloomDay.size()) return -1;
        int low=1, high=*max_element(begin(bloomDay), end(bloomDay));
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            int x = helper(bloomDay, k, mid);
            cout << mid << " " << x << endl;
            if(x >= m){
                high = mid-1;
                ans = mid;
            }
            else
                low = mid+1;
            
        }
        return ans;
    }
};
