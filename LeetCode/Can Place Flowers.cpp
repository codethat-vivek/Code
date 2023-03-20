// Question Link - https://leetcode.com/problems/can-place-flowers/

// Solution - 

class Solution {
public:
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, i = 0;
        if(flowerbed.size() == 1 && flowerbed[0] == 0)
            return true;
        
        while(i < flowerbed.size()){
            if(flowerbed[i] == 1){
                i += 2;
                continue;
            }
            
            if((i-1 >= 0 && i+1 < flowerbed.size() && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) || (i-1 < 0 && i+1 < flowerbed.size() && flowerbed[i+1] == 0) || (i-1 >= 0 && i+1 >= flowerbed.size() && flowerbed[i-1] == 0)){
                i += 2;
                cnt++;
                continue;
            }
            
            i++;
        }
        cout << cnt << "\n";
        return cnt>=n;
    }
};
