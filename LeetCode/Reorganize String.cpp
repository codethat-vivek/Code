// Question Link - https://leetcode.com/problems/reorganize-string/

// Solution - 

class Solution {
public:
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b){
        return a.second > b.second;
    }

    string reorganizeString(string s) {
        int n = s.length();
        
        // just hashing the characters in the string
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
            if(mp[c] > (n+1)/2)
                return "";
        }
        
        // creating a vector of pair and then sorting the vector according to it's value
        // in decreasing order
        vector<pair<char, int> > A;
        for (auto& it : mp)
            A.push_back(it);
        sort(A.begin(), A.end(), cmp);
        
        // filling the array of chars(ans) with characters in the required place 
        vector<char>ans(n);
        int k = 0;
        for(auto x : A){
            int t = x.second;
            while(k < n && t--){
                ans[k] = x.first;
                k += 2;
            }
            if(k >= n)
                k = 1;
            while(t>0){
                ans[k] = x.first;
                k += 2;
                t--;
            }
        }
        
        string result = "";
        for(int i=0; i<n; i++)
            result += char(ans[i]);
        return result;
        
    }
};
