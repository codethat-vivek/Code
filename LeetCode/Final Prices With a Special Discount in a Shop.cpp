// Question Link - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

// Solution - 

#define pii pair<int, int>

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> arr(n, -1);
        stack<pii>st;
        for(int i=0; i<n; i++){
            if(!st.empty() && st.top().first >= prices[i]){
                while(!st.empty() && st.top().first >= prices[i]){
                    arr[st.top().second] = i;
                    st.pop();
                }
            }
            st.push({prices[i], i}); 
        }
        
        
        for(int i=0; i<n; i++){
            if(arr[i] != -1)
                prices[i] -= prices[arr[i]];
        }
        
        return prices;
    }
};
