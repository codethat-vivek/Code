// Question Link - https://leetcode.com/problems/maximum-average-pass-ratio/

// Solution - 

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int c = classes.size();
        vector<double> arr(c, 0.0);
        vector<double> hyp(c, 0.0);
        
        // Calculate initial ratios
        double sm = 0.0;
        for (int i = 0; i < c; ++i) {
            arr[i] = (double) classes[i][0] / classes[i][1];
            sm += arr[i];
            hyp[i] = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        }
        
        // Priority queue to store the difference between the current and hypothetical ratio
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < c; ++i) {
            pq.push({hyp[i]-arr[i], i});
        }
        
        double ans = (sm*1.0)/ c;
        
        // Distribute extra students
        while (extraStudents--) {
            auto [diff, idx] = pq.top();
            pq.pop();
            
            // Update the total sum and class ratios
            ans = (sm + diff) / c;
            sm += diff;
            
            // Update the class values
            classes[idx][0] += 1;
            classes[idx][1] += 1;
            
            // Update the arrays for new class values
            arr[idx] = (double) classes[idx][0] / classes[idx][1];
            hyp[idx] = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            
            // Push the new difference back into the priority queue
            pq.push({hyp[idx] - arr[idx], idx});
        }
        
        return ans;
        
    }
};
