// Question Link - https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/

// Solution - 

class Solution {
public:
    
    int findScore(vector<int>arr){
        int score = 0;
        for(int i=0; i<arr.size(); i++){
            if((i >= 1 && arr[i-1] == 10) || (i >= 2 && arr[i-2] == 10) )
                score += arr[i];
            score += arr[i];
        }
        return score;
    }
    
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int first = findScore(player1), second = findScore(player2);
        //cout << first << " " << second << endl;
        return first > second ? 1 : first == second ? 0 : 2;
    
    }
};
