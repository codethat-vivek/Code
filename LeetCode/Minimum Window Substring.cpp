// Question Link - https://leetcode.com/problems/minimum-window-substring/

// Solution - 

class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.length();
    
        int i=0, j=0;
        string ans = "";
        unordered_map<char, int>um;
        for(char c : t)
            um[c]++;
        int mapSize = um.size();
        while(j < len){
            if(um.find(s[j]) != um.end()){
                um[s[j]]--;
                if(um[s[j]] == 0)
                    mapSize--;
            }
            if(mapSize == 0){
                while(mapSize == 0){
                    if(um.find(s[i]) != um.end()){
                        um[s[i]]++;
                        if(um[s[i]] > 0)
                            mapSize++;
                    }
                    i++;
                }
                if(ans == "" || ans.length() > j-i+1)
                    ans = s.substr(i-1, j-i+2);
            }
            j++;
        }
        return ans;
    }
};
