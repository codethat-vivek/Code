// Question Link - https://leetcode.com/problems/maximum-number-of-removable-characters/

// Solution - 

class Solution {
public:
    bool isSubsequence(string str, string sub){
        // return true if sub is subsequence of str
        int m=str.length(), n=sub.length();
        int i=0, j=0;
        while(i < m && j < n){
            if(str[i] == sub[j]){
                i++;
                j++;
            }
            else
                i++;
        }
        if(j == n) return true;
        return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low=0, high=removable.size();
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            string temp = s;
            for(int i=0; i<mid; i++)
                temp[removable[i]] = '#';
            if(isSubsequence(temp, p)){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
