// Question Link - https://leetcode.com/problems/maximum-product-of-word-lengths/

// Solution - 

class Solution {
public:
    
    int bitMask(string s){
        int bit = 0;
        for(char c : s){
            bit = bit | (1 << (c-'a'));
        }
        return bit;
    }
    
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        vector<int>helper(n);
        for(int i=0; i<n; i++)
            helper[i] = bitMask(words[i]);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if( (helper[i] & helper[j]) == 0)
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                
            }
        }
        return ans;
    }
};
