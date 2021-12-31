// Question Link - https://leetcode.com/problems/smallest-integer-divisible-by-k/

// Solution - 

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0)return -1;
        if(k == 1)return 1;
        vector<int>v;
        v.push_back(1);
        int i = 0, t;
        while (1){
            t = (v[i++]*(10%k)+1)%k;
            if(t == 0)return v.size()+1; 
            v.push_back(t);
        }
        return -1;
        
    }
};
