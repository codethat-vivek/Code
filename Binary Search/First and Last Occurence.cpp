// FIRST AND LAST OCCURENCE OF A NUMBER IN A GIVEN SORTED ARRAY 

#include <bits/stdc++.h>

using namespace std;

int firstOccurence(vector<int>v, int k, int start, int end){
    int mid;
    int ans = INT_MAX;
    while(start <= end){
        mid = start + (end - start)/2; // to avoid overflows
        if(v[mid] == k){
            ans = min(ans, mid);
            end = mid-1;
        }
        else if(v[mid] < k)
            start = mid+1;
        else
            end = mid-1;
    }
    if(ans != INT_MAX)
        return ans;
    return -1; // not found
}

int lastOccurence(vector<int>v, int k, int start, int end){
    int mid;
    int ans = INT_MIN;
    while(start <= end){
        mid = start + (end - start)/2; // to avoid overflows
        if(v[mid] == k){
            ans = max(ans, mid);
            start = mid+1;
        }
        else if(v[mid] < k)
            start = mid+1;
        else
            end = mid-1;
    }
    if(ans != INT_MIN)
        return ans;
    return -1; // not found
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
    
    int idx = firstOccurence(v, target, 0, n-1);
    int idx1 = lastOccurence(v, target, 0, n-1);
    
    cout << idx << " " << idx1 << "\n";
    
   return 0;
}
