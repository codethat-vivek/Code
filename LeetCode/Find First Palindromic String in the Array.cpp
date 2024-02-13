// Question Link - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// Solution - 

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s : words){
            int i=0, j=s.length()-1;
            while(i < j){
                if(s[i] == s[j]){
                    i++;
                    j--;
                }
                else
                    break;
            }
            if(i >= j)
                return s;
        }   
        return "";
    }
};
