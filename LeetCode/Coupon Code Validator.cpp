// Question Link - https://leetcode.com/problems/coupon-code-validator/

// Solution - 

class Solution {
public:

    bool isValidCode(string code){
        if(code.length() == 0)
            return false;
        for(int i=0; i<code.length(); i++){
            if(code[i] >= 65 && code[i] <= 90)
                continue;//uppercase
            if(code[i] >= 48 && code[i] <= 57)
                continue;//digits
            if(code[i] >= 97 && code[i] <= 122)
                continue;//lowercase
            if(code[i] == '_')
                continue;//underscore
            return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        map<string, vector<string>>businessCodeMap;
        for(int i=0; i<n; i++){
            if(!isActive[i]) continue;
            if(businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant"){
                if(!isValidCode(code[i])) continue;
                businessCodeMap[businessLine[i]].push_back(code[i]);
            }
        }
        vector<string>elec = businessCodeMap["electronics"];
        vector<string>groc = businessCodeMap["grocery"];
        vector<string>phar = businessCodeMap["pharmacy"];
        vector<string>rest = businessCodeMap["restaurant"];

        sort(elec.begin(), elec.end());
        sort(groc.begin(), groc.end());
        sort(phar.begin(), phar.end());
        sort(rest.begin(), rest.end());

        vector<string>ans;
        for(string e : elec)
            ans.push_back(e);
        for(string g : groc)
            ans.push_back(g);
        for(string p : phar)
            ans.push_back(p);
        for(string r : rest)
            ans.push_back(r);
        return ans;
    }
};
