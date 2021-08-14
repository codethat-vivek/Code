// Question Link - https://leetcode.com/problems/number-of-matching-subsequences/

// Solution - 

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        /*
         Here we need to maintain a map which will store the starting indexex of every char in string s. For Ex -> 
         if s = "abcadcab", the map should look something like this -
                 [
                  'a' -> [0, 3, 6],
                  'b' -> [1, 7],
                  'c' -> [3, 5],
                  'd' -> [4]
                 ]
        */
        map<char, vector<int>>mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]].push_back(i);
        int ans = 0;
        for(auto word : words){
            int latest = -1;
            for(int j=0; j<word.size(); j++){
                auto next = upper_bound(mp[word[j]].begin(), mp[word[j]].end(), latest);
                if(next == mp[word[j]].end())break;
                if(j == word.size() - 1)
                    ans++;
                latest = *next;
            }
        }
        return ans;
    }
};
