// Question Link - https://leetcode.com/problems/reverse-pairs/

// Solution - 

#define ll long long int

class Solution {
public:
    
    int merge(vector<int>&nums, int start, int mid, int end){
        int i=start, j=mid+1, idx=start, ans=0;
        vector<int>temp;
        while(i <= mid && j <= end){
            if((ll)nums[i] > (ll)2*nums[j]){
                ans += (mid-i+1);
                j++;
            }
            else
                i++;
        }
        i = start, j = mid+1;
        
        while(i <= mid && j <= end){
            if(nums[i] > nums[j]){
                temp.push_back(nums[j]);
                j ++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        
        while(i <= mid)
            temp.push_back(nums[i++]);
        
        while(j <= end)
            temp.push_back(nums[j++]);
        
        for(int x=0; x<temp.size(); x++)
            nums[idx++] = temp[x];
        
        return ans;
        
        
        
    }
    
    int partition(vector<int>&nums, int start, int end){
        if(start >= end) return 0;
        int mid = start + (end - start)/2, ans = 0;
        ans += partition(nums, start, mid);
        ans += partition(nums, mid+1, end);
        
        ans += merge(nums, start, mid, end);
        
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return partition(nums, 0, nums.size()-1);
    }
};
