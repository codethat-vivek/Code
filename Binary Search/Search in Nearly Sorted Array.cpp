// FIND THE GIVEN ELEMENT x IN THE NEARLY SORTED ARRAY 

// NEARLY SORTED ARRAY -> EVERY ELEMENT A[i] IN THIS ARRAY WILL HAVE A[I-1], A[I], A[I+1] POSITION IN COMPLETELY SORTED ARRAY.
// IN OTHER WORDS IN NEARLY SORTED ARRAY THE ELEMENTS ARE EITHER AT THEIR ORIGINAL PLACE (IF SORTED) OR 1 PLACE EITHER TO LEFT OR TO ITS RIGHT.
// FOR EX -> ARR = [1, 3, 2, 5] IS NEARLY SORTED AS 2 IS 1 POSITION TO THE RIGHT FROM IT'S ACTUAL PLACE IN THE SORTED ARRAY AND SAME GOES FOR 3.
// ARR = [1, 3, 2, 5, 4, 7, 6, 8] IS ALSO NEARLY SORTED, BUT ARR = [2, 3, 1, 4, 5, 6, 7, 8] IS NOT NEARLY SORTED AS 1 IS 2 POSITIONS TO THE RIGHT FROM IT'S ACTUAL PLACE.

#include <bits/stdc++.h>

using namespace std;

int findTarget(vector<int>v, int start, int end,  int target){
    int mid;
    while(start <= end){
        mid = start + (end - start)/2;
        if(v[mid] == target)
            return mid;
        if(mid-1 >= start && v[mid-1] == target) // mid-1 >= start , this is important for the bounds
            return mid-1;
        if(mid+1 <= end && v[mid+1] == target) // mid+1 <= end, same as above.
            return mid+1;
        else if(target < v[mid])
            end = mid-2;
        else
            start = mid+2;
    }
    return -1; // not found
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
    
    int idx = findTarget(v, 0, n-1, target);
    cout << idx << endl;
    
   return 0;
}
