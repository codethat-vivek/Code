// Question Link - 

// Solution - 

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char answer = keysPressed[0];
        int highest = releaseTimes[0];
        for(int i=1; i<releaseTimes.size(); i++){
            int diff = releaseTimes[i]-releaseTimes[i-1];
            //cout << diff << " ";
            if(highest < diff){
                highest = diff;
                answer = keysPressed[i];
            }
            else if(highest == diff && answer < keysPressed[i])
                answer = keysPressed[i];
            //cout << answer << endl;
        }
        return answer;
    }
};
