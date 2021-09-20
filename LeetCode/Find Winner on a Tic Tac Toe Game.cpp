// Question Link - https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

// Solution - 

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int arr[3][3];
        int n = moves.size();
        for(int i=0; i<moves.size(); i++){
            if(i % 2 == 0)
                arr[moves[i][0]][moves[i][1]] = 1;
            else
                arr[moves[i][0]][moves[i][1]] = 2;
        }

        for(int i=0; i<3; i++){ // horizontal
            if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
                if(arr[i][0] == 1)
                    return "A";
                return "B";
            }
        }
        for(int i=0; i<3; i++){ // vertical
            if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
                if(arr[0][i] == 1)
                    return "A";
                return "B";
            }
        }
        
        if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){ // first diagonal
            if(arr[0][0] == 1)
                return "A";
            return "B";
        }
        if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){ // second diagonal
            if(arr[0][2] == 1)
                return "A";
            return "B";
        }
        
        if(n == 9)
            return "Draw";
        return "Pending";
    }
};
