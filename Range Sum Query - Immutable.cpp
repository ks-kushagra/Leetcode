Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
 

Constraints:

You may assume that the array does not change.
There are many calls to sumRange function.
0 <= nums.length <= 10^4
-10^5 <= nums.length <= 10^5
0 <= i <= j < nums.length

_________________________________________________________________________________________________________________________________________________________________________________________________________
class NumArray {
public:
    vector <int> t;
    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)
                t.push_back(nums[i]);
            else
            {
                t.push_back(t[i-1]+nums[i]);
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return t[j];
        
        return t[j] -t[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
