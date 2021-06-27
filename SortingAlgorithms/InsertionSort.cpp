/*

INSERTION SORT ->
                  Time Complexity(Worst) = O(n^2)
                  Time Complexity(Best) = O(n)
                  Space Complexity = O(1) 
                  In-Place - Yes
                  Stable - Yes
                  Online - Yes
                  ***This algorithm can be used when the array is almost sorted***
                  
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

vector<ll> insertionSort(ll n, vector<ll>arr){
	int key;
	int k;
	for(int i=1; i<n; i++){
		key = arr[i];
		k = i;
		for(int j=i-1; j >= 0; j--){
			if(key < arr[j]){
				swap(arr[k], arr[j]);
				k = j;
			}
		}
	}
	return arr;
}

int main()
{	
	vector<ll>arr = {12, 11, 13, 5, 6, 100, 55, 34, 38, 2, 3, 9, 29, 99};
	vector<ll>ans = insertionSort(arr.size(), arr);
	for(auto x : ans)
		cout << x << " ";
	cout << "\n";

	return 0;
}
