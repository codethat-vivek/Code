// Question Link - https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

// Solution - 

class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0, j=0, n=s.length();
        int k = 3; // substring size you require
        map<char, int>mp;
        int ans = 0;
        while(j < n){
            mp[s[j]]++;
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k){
                if(mp.size() == k){
                    ans++;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};
