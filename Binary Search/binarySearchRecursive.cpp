// BINARY SEARCH IN A SORTED ARRAY RECURSIVELY ->

#include <bits/stdc++.h>

using namespace std;

int binarySearchRecursive(vector<int>v, int k, int start, int end){
    if(start > end)
        return -1; // not found condition
    int mid;
    mid = start + (end - start)/2; // to avoid overflows
    if(v[mid] == k)
        return mid;
    if(v[mid] < k)
        return binarySearchRecursive(v, k, mid+1, end);
    if(v[mid] > k)
        return binarySearchRecursive(v, k, start, mid-1);
}

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int target;
    cin >> target;
  
    int idx = binarySearchRecursive(v, target, 0, n-1);
    
    cout << idx << "\n";
    
   return 0;
}
