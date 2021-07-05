// Question Link - https://leetcode.com/problems/unique-email-addresses/

// Solution - 

class Solution {
public:
    
    string validate(string email){
        bool domain = false;
        bool plus = false;
        string ans = "";
        for(char c : email){
            if(c == '@'){
                domain = true;
                plus = false;
            }
            if(domain == false && c == '.')
                continue;
            if(plus == false && c == '+'){
                plus = true;
                continue;
            }
            if(plus == true)
                continue;
            ans += c;
        }
        return ans;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        set<string>st;
        for(int i=0; i<emails.size(); i++){
            string validated = validate(emails[i]);
            st.insert(validated);
        }
        return st.size();
    }
};
