// Question Link - https://leetcode.com/problems/valid-palindrome/

// Solution - 

class Solution {
public:
    bool check(string s){
        int i=0, j=s.length()-1;
        while(i < j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string new_string = "";
        for(char c : s){
            if((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90))
                new_string += tolower(c);
        }
        cout << new_string << endl;
        return check(new_string);
    }
};
