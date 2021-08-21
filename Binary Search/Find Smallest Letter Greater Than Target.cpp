// Question Link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/

// Solution - 

class Solution {
public:
    
    int find(vector<char>letters, char target, int start, int end){
        int mid, n = letters.size();
        int res = -1;
        while(start <= end){
            mid = start + (end - start)/2;
            
            if(letters[mid] == target){
                if(mid+1 < n)
                    start = mid+1;
                else
                    return 0;
            }
            else if(letters[mid] < target)
                start = mid+1;
            else{
                end = mid-1;
                res = mid;
            }
        }
        return res;
    }
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = find(letters, target, 0, letters.size() - 1);
        if(idx == -1)
            return letters[0];
        return letters[idx];
    }
};
