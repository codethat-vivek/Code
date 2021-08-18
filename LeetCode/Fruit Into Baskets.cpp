// Question Link - https://leetcode.com/problems/fruit-into-baskets/

// Solution - 

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0, j=0;
        int ans = 0;
        unordered_map<int, int>um;
        while(j < n){
            um[fruits[j]]++;
            
            if((int)um.size() > 2){
                while((int)um.size() > 2){
                    um[fruits[i]]--;
                    if(um[fruits[i]] == 0)
                        um.erase(fruits[i]);
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
