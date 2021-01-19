// Question Link - https://leetcode.com/problems/valid-sudoku/

// Solution Details - https://leetcode.com/submissions/detail/445186174/

// SOLUTION - 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> mySet;
	    for(int i=0; i<9; i++){
	        for(int j=0; j<9; j++){
	            char number = board[i][j];
	            if(number == '.')
	                continue;
	            else if(mySet.find(to_string(number) + "added in row" + to_string(i)) == mySet.end() && 
              mySet.find(to_string(number) + "added in column" + to_string(j)) == mySet.end() && 
              mySet.find(to_string(number) + "added in subBox" + to_string(i/3) + " and " + to_string(j/3)) == mySet.end()){
    	           mySet.insert(to_string(number) + "added in row" + to_string(i));
    	           mySet.insert(to_string(number) + "added in column" + to_string(j));
    	           mySet.insert(to_string(number) + "added in subBox" + to_string(i/3) + " and " + to_string(j/3));
	       }
	       else
	           return false;
	   }
	}
	return true;
    }
};
