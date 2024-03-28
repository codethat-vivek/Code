// Question Link - https://leetcode.com/problems/the-kth-factor-of-n/

// Solution - 

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>firstGroup, secondGroup;
        int i=1, t=k;
        while(i*i <= n && k != 0){
            if(n % i == 0){
                if(i == n/i)
                    firstGroup.push_back(i);
                else{
                    firstGroup.push_back(i);
                    secondGroup.push_back(n/i);
                }
                k--;
            }
            i ++;
        }
        if(t <= firstGroup.size())
            return firstGroup[t-1];
        reverse(begin(secondGroup), end(secondGroup));
        if(t-firstGroup.size() <= secondGroup.size())
            return secondGroup[t-firstGroup.size()-1];
        return -1;
    }
};
