// Question Link - https://leetcode.com/problems/rotate-array/

// Solution - 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int i=n-k;
        int pos = i;
        int x = i;
        int temp = nums[pos];
        int temp1;
        int total_count = 0;
        for(int j=x; j<n; j++){
            i = j;
            pos = i;
            x = i;
            temp = nums[pos];
            do{
                i = (pos+k)%n;
                temp1 = nums[i];
                nums[i] = temp;
                pos = i;
                temp = temp1;
                total_count ++;

            }while(x != i);
            if(total_count >= n)
                break;
        }
        
    }
};
