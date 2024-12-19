// Question Link - https://leetcode.com/problems/max-chunks-to-make-sorted/

// Solution - 

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx=-1, cnt=0, chunks=0;
        for(int i=0; i<n; i++){
            cnt++;
            if(mx < arr[i])
                mx = arr[i];
            if(mx+1 == cnt){
                chunks++;
                mx = -1;
            }
        }
        
        return chunks;
    }
};
