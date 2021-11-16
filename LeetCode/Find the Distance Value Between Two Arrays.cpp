// Question Link - https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

// Solution - 

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i : arr1){
            bool done = true;
            for(int j : arr2){
                if(abs(i-j) <= d){
                    done = false;
                    break;
                }
            }
            if(done) ans++;
        }
        return ans;
    }
};
