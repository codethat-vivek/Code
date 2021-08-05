// Question Link - https://leetcode.com/problems/boats-to-save-people/

// Solution - 

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n = people.size();
        sort(people.begin(), people.end());
        int i=0, j=n-1;
        while(i < j){
            int sm = people[i]+people[j];
            if(sm > limit)
                j--;
            else{
                i++;
                j--;
            }
            ans++;
        }
        if(i == j)
            ans+=1;
        return ans;
    }
};
