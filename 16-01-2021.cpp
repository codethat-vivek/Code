/*
Question -
  Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (arr[][]) the task to check if the configuration has a solution or not. 

Constraints:
1<=T<=10
0<=mat[]<=9
0 in the input denotes blank spaces

Input:
2
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6 1 8 7 9 2 0 2 3 7 5 9 2 2 8 9 7 3 6 1 2 9 3 1 9 4 7 8 4 5 0 3 6 1 0 6 3 2 0 6 1 5 5 4 7 6 5 6 9 3 7 4 5 2 5 4 7 4 4 3 0 7 

Output:
1
0

*/

// SOLUTION -

#include <bits/stdc++.h>
using namespace std;

int ansFunction(int arr[9][9]){
  unordered_set<string> mySet;
	for(int i=0; i<9; i++){
	   for(int j=0; j<9; j++){
	       char number = arr[i][j];
	       if(number == 0)
	            continue;
	       else if(mySet.find(number + "added in row" + to_string(i)) == mySet.end() && mySet.find(number + "added in column" + to_string(j)) == mySet.end() 
                  && mySet.find(number + "added in subBox" + to_string(i/3) + " and " + to_string(j/3)) == mySet.end()){
    	           mySet.insert(number + "added in row" + to_string(i));
    	           mySet.insert(number + "added in column" + to_string(j));
    	           mySet.insert(number + "added in subBox" + to_string(i/3) + " and " + to_string(j/3));
	       }
	       else
	           return 0;
	   }
	}
	return 1;
}


int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int arr[9][9];
	    for(int i=0; i<9; i++){
	        for(int j=0; j<9; j++)
	            cin >> arr[i][j];
	    }
	    cout << ansFunction(arr) << endl;   
    }
	    
	return 0;
}
