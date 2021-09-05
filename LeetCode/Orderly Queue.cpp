// Question Link - https://leetcode.com/problems/orderly-queue/

// Solution - 

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){ // rotate and get the answer
            deque<char>dq;
            for(auto each : s)
                dq.push_back(each);
            
            int n = s.length();
            string another = s;
            string res = s;
            
            for(int i=0; i<n; i++){
                another = another.substr(1, n-1) +dq.front();
                dq.push_back(dq.front());
                dq.pop_front();
                if(another < res)
                    res = another;
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};

/*

cba -> bac -> acb
coding (k = 2) -> cdingo -> ingocd -> ngocdi -> nocdig -> cdigno

*/
