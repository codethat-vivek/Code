// SEARCH IN A ROW WISE AND COLUMN WISE SORTED MATRIX:

// Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. 
// Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. 
// The designed algorithm should have linear time complexity.

#include <bits/stdc++.h>

using namespace std;

pair<int, int> find(vector<vector<int>> arr, int target){
    int rows = arr.size();
    int cols = arr[0].size();
    int i = 0;
    int j = cols-1;
    while(i < rows && j >= 0){
        if(arr[i][j] == target)
            return {i, j};
        else if(arr[i][j] > target)
            j--;
        else
            i++;
    }
    return {-1, -1}; // not found
}

int main()
{
    vector<vector<int>> arr = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 45}, {32, 33, 39, 50}};
    int target;
    cin >> target;
    
    auto ans = find(arr, target);
    if(ans.first == -1)
        cout << "NOT FOUND" << endl;
    else
        cout << ans.first << " " << ans.second << endl;
    
    return 0;
}
