// Question Link - https://leetcode.com/problems/find-k-closest-elements/

// Solution - 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int n = arr.size();
        int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(lb == 0){
            for(int i=0; i<k && i<n; i++)
                ans.push_back(arr[i]);
            return ans;
        }
        if(lb > n-1){
            for(int i=n-k; i<=n-1; i++)
                ans.push_back(arr[i]);
            return ans;
        }
        
        cout << ub << " " << lb << "\n";
        int same = ub - lb;
        // 'same' -  number of elements that are exactly equal to x
        if(same >= k){
            for(int i=0; i<k; i++)
                ans.push_back(x);
            return ans;
        }
        
        int more = k - same;
        
        // lb -> number of elements that are smaller than x;
        // n - ub -> number of elements that are greater than x;
        
        int i=lb-1, j=ub;
        //vector<int>greaterThan;
        
        while(i >= 0 && j < n && more != 0){
            if(x-arr[i] <= arr[j]-x)
                ans.push_back(arr[i--]);
            else
                ans.push_back(arr[j++]);
            more --;
        }
        
        while(i>=0 && more != 0){
            // there is no element to the right of ub to pick
            ans.push_back(arr[i--]);
            more --;
        }

        while(j<=n-1 && more != 0){
            // there is no element to the left of the lb to pick
            ans.push_back(arr[j++]);
            more --;
            
        }
        
        for(int lm=0; lm<same; lm++)
            ans.push_back(x);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
