// Question Link - https://leetcode.com/problems/gray-code/

// Solution - 

class Solution {
public:
    vector<int> grayCode(int n) {
        /*
        One very important property for the gray code will be that if we take xor of any two values in 
        this graycode we would get only one 1 and the rest will be 0 since there must be difference in 
        only 1 bit.
        
        
        n = 3 -> [0,1,3,2,6,7,5,4]
        n = 4 -> [0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8]
        n = 5 -> [0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8,24,25,27,26,30,31,29,28,20,21,23,22,18,19,17,16]
        */

        if(n == 1)
            return {0, 1};
        
        // first we calculate for the previous graycode for value n-1
        vector<int>prev = grayCode(n-1);
        vector<int>v;
        for(auto x : prev){
            v.push_back(x);
        }
        
        // I just took xor of every prev value with pow(2, n-1) and it to our final list
        // Because a^b = c => c^a = b and c^b = a
        // So if we xor our prev elements with pow(2, n-1) we will get our required elements of gray code
        int power = pow(2, n-1);
        for(int i=power-1; i>=0; i--){
            v.push_back(v[i]^power);
        }
        
        return v;
    }
};
