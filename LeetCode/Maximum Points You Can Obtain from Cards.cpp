// Question Link - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// Solution - 

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // choosing k elements from end points is same as choosing n-k elements whose sum is minimum
        
        int n = cardPoints.size();
        k = n - k;

        int i=0, j=0, total=0;
        for(int i : cardPoints)total+=i;
        if(k == 0)return total;
        int minSum = INT_MAX;
        int sm = 0;
        
        
        while(j < n){
            sm += cardPoints[j];
            if(j-i+1 == k)
                minSum = min(minSum, sm);
            else if(j-i+1 > k){
                sm -= cardPoints[i++];
                minSum = min(minSum, sm);
            }
            j++;
        }
        
        return total-minSum;
    }
};
