// Question Link - https://leetcode.com/problems/maximum-product-after-k-increments/

// Solution - 

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long int inf = 1e9+7;
        priority_queue<long long int, vector<long long int> ,greater<long long int>>pq;
        for(int i : nums)
            pq.push(i);
        
        while(k--){
            long long int e = pq.top();
            //cout << e << " ";
            pq.pop();
            pq.push(e+1);
        }
        
        long long int ans = 1;
        while(!pq.empty()){
            long long int ele = pq.top();
            pq.pop();
            ans = (ans*ele)%inf;
        }
        
        return ans;
        
    }
};
