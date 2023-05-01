// Question Link - https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

// Solution - 

class Solution {
public:
    double average(vector<int>& salary) {
        int mx = 0, mn = 1e7;
        for(int i=0; i<salary.size(); i++){
            if(mx < salary[i])
                mx = salary[i];
            if(mn > salary[i])
                mn = salary[i];
        }
        double sum = accumulate(salary.begin(), salary.end(), 0);
        return ((sum-mx-mn)*1.0)/(salary.size()-2);
    }
};
