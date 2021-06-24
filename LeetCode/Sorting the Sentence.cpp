// Question Link - https://leetcode.com/problems/sorting-the-sentence/

// Solution - 

class Solution {
public:
    
    vector<string> tokenize(string s, string delimeter){
        vector<string>ans;
        int start = 0;
        int end = s.find(delimeter);
        while(end != string::npos){
            ans.push_back(s.substr(start, end-start));
            start = end + delimeter.size();
            end = s.find(delimeter, start);
        }
        ans.push_back(s.substr(start, end-start));
        return ans;
    }
    
    string sortSentence(string s) {
        vector<string>x = tokenize(s, " ");
        int len = x.size();
        vector<string>ans(len+1);
        int i=0;
        for(string word: x){
            int n = word.size();
            ans[word[n-1]-'0'] = word.substr(0, n-1);
        }
        string answer = "";
        for(int i=1; i<len+1; i++){
            answer += ans[i];
            if(i != len){
                answer += " ";
            }
        }
        return answer;
    }
};
