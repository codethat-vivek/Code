// FIND THE NUMBER OF TIMES THE GIVEN ARRAY HAS BEEN ROTATED.
// FOR EX -> [2, 3, 4, 1], ans for this array should be 1

#include <bits/stdc++.h>

using namespace std;

int numRotations(vector<int>v, int start, int end){
    if(end == 0)
        return 0;
    int mid, n = v.size();
    while(start <= end){
        mid = start + (end-start)/2;
        if(mid == 0){
            if(v[mid] > v[mid+1])
                return n-1;
            return 0;
        }
        if(mid == n-1){
            if(v[mid] < v[mid-1])
                return 1;
            return 0;
        }
        if(v[mid] < v[mid-1] && v[mid] < v[mid+1])
            return n-mid;
        else if(v[mid] > v[0])
            start = mid+1;
        else if(v[mid] < v[0])
            end = mid-1;
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    
    int ans = numRotations(v, 0, n-1);
    
    cout << ans << "\n";

   return 0;
}
