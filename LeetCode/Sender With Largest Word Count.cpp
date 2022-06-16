// Question Link - https://leetcode.com/problems/sender-with-largest-word-count/

// Solution - 

class Solution {
public:
    int wordCount(string sentence){
        int count = 0;
        for (int i = 0; sentence[i] != '\0';i++){
            if (sentence[i] == ' ')count++;    
        }
        return count+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int>um;
        for(int i=0; i<senders.size(); i++)
            um[senders[i]] += wordCount(messages[i]);
        
        string ans = "";
        int mx = -1;
        for(auto &t : um){
            cout << t.first << " " << t.second << endl;
        }
        for(auto &t : um){
            if(mx < t.second){
                mx = t.second;
                ans = t.first;
            }
            else if(mx == t.second){
                if(ans < t.first)
                    ans = t.first;
            }
        }
        return ans;
    }
};
