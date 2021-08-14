// Question Link - https://leetcode.com/problems/zigzag-conversion/

// Solution - 

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1 || numRows >= n)
            return s;
        vector<vector<char>> arr(numRows, vector<char>(10001, '0'));
        int row = 0, col = 0;
        bool vertical = true, diagonal = false;
        for(int i=0; i<n; i++){
            arr[row][col] = s[i];
            if(vertical){
                if(row == numRows-1){
                    row--;
                    col++;
                    vertical = false;
                    diagonal = true;
                }
                else
                    row++;
                
            }
            else if(diagonal){
                if(row == 0){
                    vertical = true;
                    diagonal = false;
                    row++;
                }
                else{
                    row--;
                    col++;
                }
            }    
        }
        
        string result = "";
        for(int i=0; i<numRows; i++){
            for(int j=0; j<10001; j++){
                if(arr[i][j] != '0')
                    result += arr[i][j];
            }
        }
        return result;
    }
    
};
