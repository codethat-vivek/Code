/*Given a square matrix[][] of size N x N.
The task is to rotate it by 90 degrees in an anti-clockwise direction
without using any extra space.
Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9
2 5 8
1 4 7
*/

// SOLUTION --

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> >matrix(n);
    for(int i=0; i<n; i++){
        matrix[i].resize(n);
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    // logic

    // Transpose of the matrix
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reversing the matrix
    int i=0, j=n-1;
     while(i<=j){
         swap(matrix[i], matrix[j]);
         i++;
         j--;
     }

    // Printing the matrix
    for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
         }
         cout << "\n";
     }

    return 0;
}
