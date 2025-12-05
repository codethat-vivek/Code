// Question Link - https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/

// Solution - 

class Solution {
public:

    int rev(int n){
        int x = 0;
        while(n){
            x = x*10 + (n%10);
            n = n / 10;
        }
        return x;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> reverseMap;
        map<int, vector<int>> positionMap;
        int len = nums.size();
        for(int i=0; i<len; i++){
            reverseMap[nums[i]] = rev(nums[i]);
            positionMap[nums[i]].push_back(i);
        }

        int ans = len + 1;
        for(int i=0; i<len; i++){
            if(positionMap.find(reverseMap[nums[i]]) == positionMap.end())
                continue;
            const vector<int>& idx = positionMap[reverseMap[nums[i]]];
            int lb = upper_bound(idx.begin(), idx.end(), i) - idx.begin();
            if (lb < idx.size())
                ans = min(ans, idx[lb] - i);
            

        }

        return ans == len + 1 ? -1 : ans;

    }
};
