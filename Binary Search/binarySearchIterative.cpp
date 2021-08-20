// BINARY SEARCH IN A SORTED ARRAY ITERATIVELY ->
#include <bits/stdc++.h>

using namespace std;

int binarySearchIterative(vector<int>v, int k, int start, int end){
    while(start <= end){
        int mid = start + (end - start)/2; // to avoid overflows
        if(v[mid] == k)
            return mid;
        else if(v[mid] < k)
            start = mid+1;
        else
            end = mid-1;
    }
    return -1; // not found condition
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
    
    int idx = binarySearchIterative(v, target, 0, n-1);
    
    cout << idx << "\n";
    
   return 0;
}
