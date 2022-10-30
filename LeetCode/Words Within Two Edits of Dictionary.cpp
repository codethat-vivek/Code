// Question Link - https://leetcode.com/problems/words-within-two-edits-of-dictionary/

// Solution - 

class Solution {
public:
    bool isSimilar(string a, string b){
        int edits = 0;
        for(int i=0; i<a.length(); i++){
            if(edits > 2) return false;
            if(a[i] != b[i]) edits++;
        }
        return edits <= 2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(int i=0; i<queries.size(); i++){
            for(int j=0; j<dictionary.size(); j++){
                if(isSimilar(queries[i], dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
