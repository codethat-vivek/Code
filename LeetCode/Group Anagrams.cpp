// Question Link - https://leetcode.com/problems/group-anagrams/

// Solution - 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>um;
        vector<vector<string>> ans;
        for(auto s : strs){
            string t = s;
            sort(s.begin(), s.end());
            um[s].push_back(t);
        }
        for(auto x : um)
            ans.push_back(x.second);
        return ans;
    }
};
