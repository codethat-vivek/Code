// Question Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Solution Details - https://leetcode.com/submissions/detail/443990615/

// SOLUTION - 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i=0, j=0;
        unordered_set <char> mySet;
        while(j<s.length()){
            if(mySet.find(s[j]) == mySet.end()){
                mySet.insert(s[j]);
                j++;
            }
            else if(mySet.find(s[j]) != mySet.end()){
                mySet.erase(s[i]);
                i++;
            }
            if(mySet.size() > ans)
                ans = mySet.size();
        }
        return ans;
    }
};
