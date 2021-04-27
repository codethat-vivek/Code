// Question Link - https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

// SOLUTION - 

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        int right = 0, left = 0;
        // for index 0
        int cnt = 0;
        for(int i=0; i<boxes.length(); i++){
            if(boxes[i] == '1'){
                right++;
                cnt += i;
            }   
        }
        ans.push_back(cnt);
        
        for(int i=1; i<boxes.length(); i++){
            if(boxes[i-1] == '1'){
                left ++;
                right --;
            }
            ans.push_back(ans[i-1] - right + left);
        }
        return ans;
        
    }
};
