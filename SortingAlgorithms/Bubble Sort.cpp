  
/*
BUBBLE SORT  ->
                  Time Complexity(Best) - O(n) # when already sorted
                  Time Complexity(Worst) - O(n^2)
                  Space Complexity - O(1)
                  In-Place - Yes
                  Stable - Yes
                  Online - No
                  
                  
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> bubbleSort(ll n, vector<ll>arr){
    for (ll i = 0; i < n-1; i++){     
        for (ll j = 0; j < n-i-1; j++){ 
            if (arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]);
        }
    }
    return arr;
}

int main()
{
    vector<ll>arr = {1, 4, 2, 36, 6, 7, 65, 3, 25, 45, 8, 9, 20, 3, 6, 0};
    vector<ll>ans = bubbleSort(arr.size(), arr);

    for(ll x : ans)
        cout << x << " ";
    

    return 0;
}
