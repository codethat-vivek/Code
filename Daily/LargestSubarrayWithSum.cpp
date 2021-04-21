/*
Question - 
Find the longest length of the subarray which has a sum equal to target(given) from a given array.

Ex - 
  Input : 
  n = 5
  arr = [4, 1, 1, 1, 2, 3, 5]
  target = 5  
  
  Output:
  4 (Since the largest subarray is [1, 1, 1, 2] and it's length is 4)
  
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int solve(vector<int> &A, const int &k) {
	int n = A.size();
	int i = 0, j = 0, sum = 0;
	int mx = INT_MIN;
	while (j < n) {
		sum += A[j];
		if (sum < k) {
			j++;
		} else if (sum == k) {
			mx = max(mx, j - i + 1);
			j++;
		} else if (sum > k) {
			while (sum > k) {
				sum = sum - A[i];
				i++;
			}
			j++;
		}
	}
	return mx;
}
int main()
{
	vector<int> A{4, 1, 1, 1, 2, 3, 5};
	int target = 5;
	cout << solve(A, target);
	return 0;
}



