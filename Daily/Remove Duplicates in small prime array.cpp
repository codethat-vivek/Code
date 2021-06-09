/*
  Question - Remove duplicates in small prime array
    Given an array consisting of only prime numbers, remove all duplicate numbers from it. 
    Note: Retain the first occurrence of the duplicate element.
  Example 1:
  Input:
  N = 6
  A[] = {2,2,3,3,7,5}
  Output: 2 3 7 5
  Explanation: After removing the duplicate
  2 and 3 we get 2 3 7 5.
  
  Expected Time Complexity: O(N).
  Expected Auxiliary Space: O(N).
*/

// SOLUTION - 

#include<bits/stdc++.h>
using namespace std;
vector<int> removeDuplicate(vector<int>& arr, int n);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        vector<int>result = removeDuplicate(A,N);
        for(int i =0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;

    }
}


vector<int> removeDuplicate(vector<int>& arr, int n)
{
    // code here
    // 2 2 3 3 7 5
    unordered_set <int> mySet;
    for(int i=0; i<arr.size(); i++){
        if(mySet.find(arr[i]) == mySet.end())
            mySet.insert(arr[i]);
        else{
            arr.erase(arr.begin()+i);
            i--;
        }
    }
    return arr;
}


