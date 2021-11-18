/*
A beautiful matrix is a matrix in which the sum of elements in each row and column is equal.
Given a square matrix of size NxN. Find the minimum number of operation(s) that are required to make the matrix beautiful. 
In one operation you can increment the value of any one cell by 1.

Example 1 -
Input:
N = 2
matrix[][] = {{1, 2},
              {3, 4}}
Output: 4
Explanation:
  Updated matrix:
  4 3
  3 4
  1. Increment value of cell(0, 0) by 3
  2. Increment value of cell(0, 1) by 1
  Hence total 4 operation are required.

Example 2 -
Input:
N = 3
matrix[][] = {{1, 2, 3},
              {4, 2, 3},
              {3, 2, 1}}
Output: 6
Explanation:
  Original matrix is as follows:
  1 2 3
  4 2 3
  3 2 1
  We need to make increment in such a way 
  that each row and column has one time 2, 
  one time 3 , one time 4. For that we 
  need 6 operations.
*/

// SOLUTION -

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxSum=0;
        int currentHorizontalSum = 0;
        int currentVerticalSum = 0;
        vector<int>sums;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                currentHorizontalSum += matrix[i][j];
                currentVerticalSum += matrix[j][i];
            }
            
            sums.push_back(currentHorizontalSum);
            int temp = max(currentHorizontalSum, currentVerticalSum);
            maxSum = max(maxSum, temp);
            currentHorizontalSum = 0;
            currentVerticalSum = 0;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += (maxSum - sums[i]);
        }
        
        return ans;
    } 
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}
