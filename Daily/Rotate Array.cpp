/*
Write a program to rotate an array A consisting of n integers by k positions.
For Example -
    Input:
        n = 5
        A = [1, 2, 3, 4, 5]
        k = 2
    Output:
        A = [3, 4, 5, 1, 2]

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int>ans;
    for(int i=0; i<n; i++){
        ans.push_back(arr[(i+k)%n]);
    }
    
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;   
}
