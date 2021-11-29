// Question Link - https://leetcode.com/problems/watering-plants/

// Solution - 

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size(), curr = capacity;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(plants[i] <= curr){
                curr -= plants[i];
                ans += 1;
            }
            else{
                ans += (2*i+1);
                curr = capacity-plants[i];
            }
        }
        return ans;
    }
};
