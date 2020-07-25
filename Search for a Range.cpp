Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

_______________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans(2,-1);
        int start = 0;
        int end = nums.size()-1;
        
        
        //First Occurance
        while(start <=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                ans[0]=mid;
                end = mid-1;
            }
            
            else if(nums[mid]<target)
                start = mid+1;
            else
                end = mid-1;
        }
        
        start=0,end=nums.size()-1;
        
        
        //Last Occurance
        while(start <=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                ans[1]=mid;
                start = mid+1;
            }
            
            else if(nums[mid]<target)
                start = mid+1;
            else
                end = mid-1;
        }
        
        
        return ans;
    }
};
