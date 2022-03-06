// Question Link - https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

// Solution - 

class Solution {
public:
    
    long long int inf = 1e9+7;
    
    int countOrders(int n) {
        vector<int>arr(n+1);
        arr[1] = 1;
        for(int i=2; i<=n; i++){
            arr[i] = ( ( (arr[i-1]%inf)*(2*i-1) )%inf*i)%inf;
        }
        return arr[n];
        
    }
};
