Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 

Constraints:

    3 <= nums.length <= 10^3
    -10^3 <= nums[i] <= 10^3
    -10^4 <= target <= 10^4


______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans=0,diff=INT_MAX;
        sort(nums.begin(),nums.end());  // -4 -1 1 2      
        int i=0;
        while(i<n-2)
        {
            int j = i+1;
            int k = n-1;
            while(j < k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target)
                    return target;
                
                if(sum > target)
                    k--;
                
                else
                    j++;
                
                if(sum > target && (sum-target) < diff )
                {
                    diff = sum-target;
                    ans = sum;
                }
                
                else if(sum < target && (target - sum ) < diff)
                {
                    diff = target - sum;
                    ans = sum;
                }
            }
            
            i++;
        }
        
        return ans;
    }
};
