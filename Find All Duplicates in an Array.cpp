Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

_______________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        nums.insert(nums.begin(),0);
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[abs(nums[i])] > 0)
                nums[abs(nums[i])] = -(nums[abs(nums[i])]);
            else
                ans.push_back(abs(nums[i]));
        }

        return ans;
        
    }
};
