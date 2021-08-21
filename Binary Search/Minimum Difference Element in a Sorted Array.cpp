// You are given an sorted array and an element x. Find the element in the sorted array such that abs(a[i]-x) is minimum.

#include <bits/stdc++.h>

using namespace std;

int findMinimumDifferenceElement(vector<int>v, int target, int start, int end){
    int mid, low, high;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == target)
            return mid;
        else if(v[mid] < target){
            low = mid;
            start = mid+1;
        }
        else{
            high = mid;
            end = mid - 1;
        }
    }
    if(abs(v[low] - target) < abs(v[high] - target))
        return low;
    return high;
}

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int target;
    cin >> target;
    
    int idx = findMinimumDifferenceElement(v, target, 0, n-1);
    cout << v[idx] << endl;
    
   return 0;
}
