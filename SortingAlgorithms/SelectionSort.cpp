/*

SELECTION SORT  ->
                  Time Complexity(Best) - O(n^2)
                  Time Complexity(Worst) - O(n^2)
                  Space Complexity - O(1)
                  In-Place - Yes
                  Stable - No
                  Online - No
                  
                  
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> selectionSort(ll n, vector<ll>arr){
    ll mn, idx;
    for(ll i=0; i<n-1; i++){
        idx = i;
        for(ll j=i+1; j<n; j++){
            if(arr[idx] > arr[j])
                idx = j;
            
        }
        swap(arr[i], arr[idx]);
    }
    return arr;
}

int main()
{
    vector<ll>arr = {1, 4, 2, 36, 6, 7, 65, 3, 25, 45, 8, 9, 20, 3, 6, 0};
    vector<ll>ans = selectionSort(arr.size(), arr);

    for(auto x : ans){
        cout << x << " ";
    }

    return 0;
}
