// Question Link - https://leetcode.com/problems/optimal-partition-of-string/

// Solution - 

class Solution {
public:
    int partitionString(string s) {
        int substrings = 1;
        unordered_set<char>us;
        for(char c : s){
            if(us.find(c) == us.end())
                us.insert(c);
            else{
                us.clear();
                us.insert(c);
                substrings++;
            }
        }
        
        return substrings;
    }
};
