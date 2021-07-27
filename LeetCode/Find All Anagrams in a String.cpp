// Question Link - https://leetcode.com/problems/find-all-anagrams-in-a-string/

// Solution - 

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Lovely Explanation -> https://www.youtube.com/watch?v=MW4lJ8Y0xXk&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=5
        vector<int>ans;
        int k = p.length();
        map<char, int>mp;
        for(char c : p)
            mp[c]++;
        int letters = mp.size();
        int i=0, j=0;
        while(j < s.length()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    letters--;
            }
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k){
                if(letters == 0)
                    ans.push_back(i);
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        letters++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
