// Question Link - https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

// Solution - 

class Solution {
public:
    double calc(vector<int> &dist, int speed){
        double ans=0;
        for(int i=0; i<dist.size(); i++){
            if(i == dist.size()-1)
                ans += (dist[i]/(1.0*speed));
            else
                ans += ceil(dist[i]/(1.0*speed));
        }
        return ans;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1, high=1000000000;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            double res = calc(dist, mid);
            //cout << mid << " " << res << endl;
            if(res > 1.0*hour){
                low = mid+1;
            }
            else{
                high = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};
