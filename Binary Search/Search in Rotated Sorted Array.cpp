// FIND THE TARGET ELEMENT IN THE GIVEN ROTATED SORTED ARRAY.

  // for finding the pivot element in the rotated sorted array
  int findPivot(vector<int>v, int start, int end){
        int mid, n = v.size();
        while(start <= end){
            mid = start + (end - start)/2;
            if(mid == 0){
                if(v[0] > v[1])
                    return 1;
                return 0;
            }
            if(mid == n-1){
                if(v[n-1] < v[n-2])
                    return n-1;
                return 0;
            }
            if(v[mid] < v[mid-1] && v[mid] < v[mid+1])
                return mid;
            else if(v[mid] < v[0])
                end = mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
    
    // normal binary search function
   int bs(vector<int>v, int k, int start, int end){
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
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target)
                return 0;
            return -1;
        }
        int pivotIndex = findPivot(nums, 0, n-1);
        //cout << pivotIndex << endl;
        if(nums[pivotIndex] == target)
            return pivotIndex;
        
        int x = bs(nums, target, pivotIndex, n-1);
        int y = bs(nums, target, 0, pivotIndex);
        if(x == -1)
            return y;
        return x;
    }

    int main(){
        vector<int>nums = {5, 6, 7, 1, 2, 3, 4};
        int target = 6;
        int idx = search(nums, target);
        if(idx != -1)
            cout << "Index of " << target << " in the array is " << idx << endl;
        cout << "The target is not present in the array" << endl;
        return 0; 
    }
