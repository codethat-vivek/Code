// Question Link - https://leetcode.com/problems/isomorphic-strings/

// Solution - 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n)
            return false;
        map<char, char>mp;
        map<char, char>mmp;
        /*
        "bbbaaaba"
        "aaabbbba"
        */
        for(int i=0; i<n; i++){
            auto it = mp.find(s[i]);
            auto iit = mmp.find(t[i]);
            if(it == mp.end() && iit == mmp.end()){
                mp[s[i]] = t[i];
                mmp[t[i]] = s[i];
            }
            else if(it == mp.end()){
                if(mmp[t[i]] != s[i])
                    return false;
                
            }
            else if(iit == mmp.end()){
                if(mp[s[i]] != t[i])
                    return false;
            }
            else{
                if(mp[s[i]] != t[i] || mmp[t[i]] != s[i] )
                    return false;
            }
        }
        return true;
    }
};
