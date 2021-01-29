/*
Given a matrix mat[][] of n rows and m columns, consisting of 0’s and 1’s. The task is to complete the function findPerimeter which returns 
an integer denoting the perimeter of sub-figures consisting of only 1’s in the matrix.

For example
Perimeter of single 1 is 4 as it can be covered from all 4 side. Perimeter of double 11 is 6.

Constraints:
1<=T<=100
1<=n, m<=20

Input:
2
1 2
1 1 
3 3
1 0 0 1 0 0 1 0 0

Output:
6
8

*/

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;
#define MAX 100


// Returns sum of perimeter of shapes formed with 1s
int findPerimeter(int mat[MAX][MAX], int n,int m);

int main() {
	int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof g);
		int n;
		cin>>n;
		int m;
		cin>>m;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<findPerimeter(g,n,m)<<endl;
	}
	
	return 0;
}


/*You are required to complete this method */
int findPerimeter(int mat[MAX][MAX], int n, int m)
{
    //Your code here
    int ans = 0;
    int current;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            current = 0;
            if(mat[i][j] == 1){
                if(i>=1 && j>=1 && i!=n-1 && j!=m-1){
                   if(mat[i-1][j] == 1)current++;
                   if(mat[i][j-1] == 1)current++;
                   if(mat[i][j+1] == 1)current++;
                   if(mat[i+1][j] == 1)current++;
                }
                else if(i == 0){
                    if(j != m-1 && mat[i][j+1] == 1)current++;
                    if(j != 0 && mat[i][j-1] == 1)current++;
                    if(i+1 < n && mat[i+1][j] == 1)current++;
                }
                else if(j == 0){
                    if(i != n-1 && mat[i+1][j] == 1)current++;
                    if(i != 0 && mat[i-1][j] == 1)current++;
                    if(mat[i][j+1] == 1)current++;
                }
                else if(i == n-1){
                    if(mat[i-1][j] == 1)current++;
                    if(j != 0 && mat[i][j-1] == 1)current++;
                    if(j != m-1 && mat[i][j+1] == 1)current++;
                }
                else if(j == m-1){
                    if(mat[i][j-1] == 1)current++;
                    if(i != 0 && mat[i-1][j] == 1)current++;
                    if(i != n-1 && mat[i+1][j] == 1)current++;
                }
                if(current == 0)ans = ans + 4;
                else if(current == 1)ans = ans + 3;
                else if(current == 2)ans = ans + 2;
                else if(current == 3)ans = ans + 1;
                
                
            }
        }
    }
    return ans;
}
