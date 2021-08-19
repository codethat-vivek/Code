// Question Link - https://practice.geeksforgeeks.org/problems/square-root/1

// Solution - 

long long int bs(long long int x){
  long long int start = 0, end = x;
	long long int mid;
	long long int ans;

	while (start <= end) {
		mid = (start + end) / 2;
		if (mid * mid == x) {
			ans = mid;
			break;
		}

		if (mid * mid < x) {
			start = mid + 1;
			ans = mid;
		}

		else 
			end = mid - 1;
		
	}
	return ans;
}

long long int floorSqrt(long long int x) 
{
    // Your code goes here  
    return bs(x);
}
