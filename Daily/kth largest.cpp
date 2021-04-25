/*
Question - 

You are given an array of integers. Your task is to find the kth smallest element of the array.

For Ex - 

Input : 
n : 7
arr : 1, 6, 2, 4, 9, 22, 10
k : 4

Output : 
6

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
      cin >> arr[i];
    }
    int k;
    cin >> k;

    priority_queue <int> p; // max heap

    for(int i=0; i<n; i++){
        p.push(arr[i]);
        if(p.size() > k){
            p.pop();
        }
    }

    cout << p.top() << endl;

    return 0;
}

